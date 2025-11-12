/*
 * Clings TUI
 * Interactive terminal UI for C programming challenges
 * Supports both casual mode (retry on failure) and rogue mode (restart on failure)
 */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_EXERCISES 200
#define MAX_OUTPUT 4096
#define MAX_PATH 256

typedef struct {
    char name[64];
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
    int current_idx;
    int cleared;
    int best_score;
    int last_result;
    char last_output[MAX_OUTPUT];
    int backup_created;
    int is_rogue_mode;
    char backup_dir[64];
    char progress_file[64];
} RogueState;

// Colors
enum {
    COLOR_PAIR_GREEN = 1,
    COLOR_PAIR_RED,
    COLOR_PAIR_YELLOW,
    COLOR_PAIR_BLUE,
    COLOR_PAIR_CYAN
};

void init_colors(void) {
    start_color();
    init_pair(COLOR_PAIR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_PAIR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_PAIR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_PAIR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_PAIR_CYAN, COLOR_CYAN, COLOR_BLACK);
}

int compare_exercises(const void *a, const void *b) {
    return strcmp(((Exercise *)a)->name, ((Exercise *)b)->name);
}

void load_exercises(RogueState *state) {
    DIR *dir = opendir("exercises");
    if (!dir) return;

    struct dirent *entry;
    state->num_exercises = 0;

    while ((entry = readdir(dir)) != NULL && state->num_exercises < MAX_EXERCISES) {
        char *ext = strrchr(entry->d_name, '.');
        if (ext && strcmp(ext, ".c") == 0) {
            size_t len = ext - entry->d_name;
            if (len < sizeof(state->exercises[0].name)) {
                strncpy(state->exercises[state->num_exercises].name, entry->d_name, len);
                state->exercises[state->num_exercises].name[len] = '\0';
                state->num_exercises++;
            }
        }
    }
    closedir(dir);
    qsort(state->exercises, state->num_exercises, sizeof(Exercise), compare_exercises);
}

int load_best_score(const char *progress_file) {
    FILE *f = fopen(progress_file, "r");
    if (!f) return 0;

    int best = 0;
    fscanf(f, "%d", &best);
    fclose(f);
    return best;
}

void save_best_score(const char *progress_file, int score, int total) {
    FILE *f = fopen(progress_file, "w");
    if (!f) return;

    fprintf(f, "%d/%d\n", score, total);
    fclose(f);
}

void create_backup(const char *backup_dir) {
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "rm -rf %s 2>/dev/null", backup_dir);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "cp -r exercises %s", backup_dir);
    system(cmd);
}

void restore_backup(const char *backup_dir) {
    char cmd[512];
    system("rm -rf exercises");
    snprintf(cmd, sizeof(cmd), "cp -r %s exercises", backup_dir);
    system(cmd);
}

void strip_ansi_codes(char *str) {
    char *src = str;
    char *dst = str;

    while (*src) {
        if (*src == '\033' && *(src + 1) == '[') {
            src += 2;
            while (*src && *src != 'm') {
                src++;
            }
            if (*src == 'm') src++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
}

int test_exercise(const char *exercise, char *output, size_t output_size) {
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "make -s run-single EXERCISE=%s 2>&1", exercise);

    FILE *fp = popen(cmd, "r");
    if (!fp) {
        strncpy(output, "Error: Could not run test", output_size - 1);
        return 0;
    }

    size_t pos = 0;
    char buf[256];
    while (fgets(buf, sizeof(buf), fp) && pos < output_size - 1) {
        size_t len = strlen(buf);
        if (pos + len < output_size - 1) {
            strcpy(output + pos, buf);
            pos += len;
        }
    }
    output[pos] = '\0';

    strip_ansi_codes(output);

    int status = pclose(fp);
    return (status == 0) ? 1 : 0;
}

char *get_hint(const char *exercise) {
    static char hint[1024];
    char filepath[MAX_PATH];
    snprintf(filepath, sizeof(filepath), ".hints/%s.txt", exercise);

    FILE *f = fopen(filepath, "r");
    if (!f) return "No hint available for this exercise yet";

    hint[0] = '\0';
    size_t pos = 0;
    char line[256];

    while (fgets(line, sizeof(line), f) && pos < sizeof(hint) - 1) {
        size_t len = strlen(line);
        if (pos + len < sizeof(hint) - 1) {
            strcpy(hint + pos, line);
            pos += len;
        }
    }
    fclose(f);

    if (hint[0] == '\0') {
        return "No hint available for this exercise yet";
    }

    size_t len = strlen(hint);
    if (len > 0 && hint[len - 1] == '\n') {
        hint[len - 1] = '\0';
    }

    return hint;
}

void draw_centered(int y, const char *text, int attr) {
    int width = COLS;
    int x = (width - strlen(text)) / 2;
    if (x < 0) x = 0;
    attron(attr);
    mvprintw(y, x, "%s", text);
    attroff(attr);
}

void draw_header(RogueState *state) {
    if (state->is_rogue_mode) {
        draw_centered(0, "== ROGUE MODE ==", COLOR_PAIR(COLOR_PAIR_RED) | A_BOLD);
    } else {
        draw_centered(0, "== CASUAL MODE ==", COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);
    }

    char progress[64];
    snprintf(progress, sizeof(progress), "Progress: %d/%d", state->cleared, state->num_exercises);
    mvprintw(1, 2, "%s", progress);

    char best[32];
    snprintf(best, sizeof(best), "Best: %d", state->best_score);
    mvprintw(1, COLS - strlen(best) - 2, "%s", best);

    attron(COLOR_PAIR(COLOR_PAIR_BLUE));
    for (int i = 0; i < COLS; i++) {
        mvaddch(2, i, ACS_HLINE);
    }
    attroff(COLOR_PAIR(COLOR_PAIR_BLUE));
}

void draw_current_exercise(RogueState *state) {
    if (state->current_idx >= state->num_exercises) return;

    char filepath[MAX_PATH];
    snprintf(filepath, sizeof(filepath), "exercises/%s.c",
             state->exercises[state->current_idx].name);

    attron(A_BOLD);
    mvprintw(4, 2, "Current Exercise:");
    attroff(A_BOLD);

    attron(COLOR_PAIR(COLOR_PAIR_CYAN));
    mvprintw(5, 4, "%s", filepath);
    attroff(COLOR_PAIR(COLOR_PAIR_CYAN));

    attron(A_BOLD);
    mvprintw(7, 2, "Status:");
    attroff(A_BOLD);

    if (state->last_result == -1) {
        attron(COLOR_PAIR(COLOR_PAIR_YELLOW));
        if (state->is_rogue_mode) {
            mvprintw(8, 4, "WAITING - Edit the file, then press 's' to submit (FAIL = RESTART!)");
        } else {
            mvprintw(8, 4, "WAITING - Edit the file, then press 's' to submit");
        }
        attroff(COLOR_PAIR(COLOR_PAIR_YELLOW));
    } else if (state->last_result == 1) {
        attron(COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);
        mvprintw(8, 4, "PASSED");
        attroff(COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);
    } else {
        attron(COLOR_PAIR(COLOR_PAIR_RED) | A_BOLD);
        mvprintw(8, 4, "FAILED");
        attroff(COLOR_PAIR(COLOR_PAIR_RED) | A_BOLD);
    }
}

void draw_output(RogueState *state) {
    if (state->last_output[0] == '\0') return;

    attron(A_BOLD);
    mvprintw(10, 2, "Last Result:");
    attroff(A_BOLD);

    char *line = strtok(state->last_output, "\n");
    int y = 11;
    int max_y = LINES - 5;

    while (line && y < max_y) {
        mvprintw(y, 4, "%.90s", line);
        line = strtok(NULL, "\n");
        y++;
    }
}

void draw_commands(void) {
    attron(COLOR_PAIR(COLOR_PAIR_BLUE));
    for (int i = 0; i < COLS; i++) {
        mvaddch(LINES - 3, i, ACS_HLINE);
    }
    attroff(COLOR_PAIR(COLOR_PAIR_BLUE));

    attron(A_BOLD);
    mvprintw(LINES - 2, 2, "[s]ubmit  [h]int  [q]uit");
    attroff(A_BOLD);
}

void draw_ui(RogueState *state) {
    clear();
    draw_header(state);
    draw_current_exercise(state);
    draw_output(state);
    draw_commands();
    refresh();
}

int game_over(RogueState *state) {
    clear();

    char msg1[] = "== GAME OVER ==";
    char msg2[64];
    snprintf(msg2, sizeof(msg2), "You cleared: %d exercises", state->cleared);

    draw_centered(LINES / 2 - 3, msg1, COLOR_PAIR(COLOR_PAIR_RED) | A_BOLD);
    draw_centered(LINES / 2 - 1, msg2, COLOR_PAIR(COLOR_PAIR_YELLOW));

    if (state->cleared > state->best_score) {
        char record[] = "== NEW RECORD ==";
        char prev[64];
        snprintf(prev, sizeof(prev), "Previous best: %d", state->best_score);

        draw_centered(LINES / 2 + 1, record, COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);
        draw_centered(LINES / 2 + 2, prev, COLOR_PAIR(COLOR_PAIR_GREEN));

        save_best_score(state->progress_file, state->cleared, state->num_exercises);
        state->best_score = state->cleared;
    } else {
        char best[64];
        snprintf(best, sizeof(best), "Best run: %d exercises", state->best_score);
        draw_centered(LINES / 2 + 1, best, COLOR_PAIR(COLOR_PAIR_BLUE));
    }

    char prompt[] = "Press Enter to restart, or 'q' to quit";
    draw_centered(LINES / 2 + 4, prompt, 0);

    refresh();

    while (1) {
        int ch = getch();
        if (ch == '\n' || ch == '\r') {
            if (state->is_rogue_mode) {
                restore_backup(state->backup_dir);
            }
            state->current_idx = 0;
            state->cleared = 0;
            state->last_result = -1;
            state->last_output[0] = '\0';
            return 1;
        } else if (ch == 'q') {
            return 0;
        }
    }
}

void victory(RogueState *state) {
    clear();

    char msg1[] = "== VICTORY ==";
    char msg2[64];
    char msg3[] = "You are a C programming master!";

    snprintf(msg2, sizeof(msg2), "You completed all %d exercises!", state->num_exercises);

    draw_centered(LINES / 2 - 2, msg1, COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);
    draw_centered(LINES / 2, msg2, COLOR_PAIR(COLOR_PAIR_GREEN));
    draw_centered(LINES / 2 + 1, msg3, COLOR_PAIR(COLOR_PAIR_GREEN) | A_BOLD);

    save_best_score(state->progress_file, state->num_exercises, state->num_exercises);

    char prompt[] = "Press any key to exit";
    draw_centered(LINES / 2 + 3, prompt, 0);

    refresh();
    getch();
}

void run_tui(RogueState *state) {
    create_backup(state->backup_dir);
    state->backup_created = 1;

    while (1) {
        draw_ui(state);

        int ch = getch();

        if (ch == 'q') {
            break;
        } else if (ch == 's') {
            if (state->current_idx < state->num_exercises) {
                char output[MAX_OUTPUT];
                const char *exercise = state->exercises[state->current_idx].name;
                int passed = test_exercise(exercise, output, sizeof(output));

                state->last_result = passed;
                strncpy(state->last_output, output, sizeof(state->last_output) - 1);
                state->last_output[sizeof(state->last_output) - 1] = '\0';

                if (passed) {
                    state->cleared++;
                    state->current_idx++;
                    state->last_result = -1;
                    state->last_output[0] = '\0';

                    if (state->current_idx >= state->num_exercises) {
                        victory(state);
                        break;
                    }
                } else {
                    if (!state->is_rogue_mode) {
                    } else {
                        if (!game_over(state)) {
                            break;
                        }
                    }
                }
            }
        } else if (ch == 'h') {
            if (state->current_idx < state->num_exercises) {
                const char *exercise = state->exercises[state->current_idx].name;
                char *hint = get_hint(exercise);
                snprintf(state->last_output, sizeof(state->last_output), "HINT: %s", hint);
                state->last_result = -1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int is_rogue = 0;
    if (argc > 1 && strcmp(argv[1], "rogue") == 0) {
        is_rogue = 1;
    }

    RogueState state = {
        .num_exercises = 0,
        .current_idx = 0,
        .cleared = 0,
        .best_score = 0,
        .last_result = -1,
        .backup_created = 0,
        .is_rogue_mode = is_rogue
    };
    state.last_output[0] = '\0';

    if (is_rogue) {
        strncpy(state.backup_dir, ".rogue_backup", sizeof(state.backup_dir));
        strncpy(state.progress_file, ".rogue_progress", sizeof(state.progress_file));
    } else {
        strncpy(state.backup_dir, ".casual_backup", sizeof(state.backup_dir));
        strncpy(state.progress_file, ".casual_progress", sizeof(state.progress_file));
    }

    load_exercises(&state);
    if (state.num_exercises == 0) {
        fprintf(stderr, "Error: No exercises found in exercises/ directory\n");
        return 1;
    }

    state.best_score = load_best_score(state.progress_file);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    init_colors();
    run_tui(&state);
    endwin();

    return 0;
}
