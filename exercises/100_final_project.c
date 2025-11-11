// Exercise 100: Final Project - Todo List Manager
//
// Congratulations! You've made it to the final exercise!
//
// This is a complete mini-project that brings together everything:
//   - Structs and dynamic memory
//   - Linked lists
//   - File I/O (save/load)
//   - User input
//   - String manipulation
//
// The program is mostly complete but has bugs throughout.
// Fix them all to complete your C learning journey!
//
// EXPECTED: Todo List Manager
// EXPECTED: 1. Add task
// EXPECTED: 2. List tasks
// EXPECTED: 3. Complete task
// EXPECTED: 4. Save & Exit
// HINT: Fix memory leaks, file operations, list management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char description[100];
    int completed;
    struct Task *next;
} Task;

Task *head = NULL;
int next_id = 1;

void add_task(const char *desc) {
    Task *new_task = malloc(sizeof(Task));
    if (new_task == NULL) return;

    new_task->id = next_id++;
    // TODO: Fix this!
    strcpy(new_task->description, desc);
    new_task->completed = 0;
    new_task->next = head;
    head = new_task;

    printf("Added task #%d\n", new_task->id);
}

void list_tasks() {
    if (head == NULL) {
        printf("No tasks!\n");
        return;
    }

    printf("\nYour tasks:\n");
    Task *current = head;
    while (current != NULL) {
        printf("[%d] %s %s\n",
               current->id,
               current->completed ? "[X]" : "[ ]",
               current->description);
        current = current->next;
    }
}

void complete_task(int id) {
    Task *current = head;
    while (current != NULL) {
        if (current->id == id) {
            current->completed = 1;
            printf("Completed task #%d\n", id);
            return;
        }
        current = current->next;
    }
    printf("Task #%d not found\n", id);
}

void save_tasks() {
    // TODO: Implement file saving!
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) return;

    Task *current = head;
    while (current != NULL) {
        fprintf(file, "%d|%d|%s\n",
                current->id, current->completed, current->description);
        current = current->next;
    }
    fclose(file);
    printf("Tasks saved!\n");
}

void free_all_tasks() {
    // TODO: Free all tasks to avoid memory leaks!
    Task *current = head;
    while (current != NULL) {
        Task *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void) {
    printf("=== Todo List Manager ===\n");

    int choice;
    char buffer[100];

    while (1) {
        printf("\n1. Add task\n");
        printf("2. List tasks\n");
        printf("3. Complete task\n");
        printf("4. Save & Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);
        getchar();  // Consume newline

        if (choice == 1) {
            printf("Task description: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
            add_task(buffer);
        } else if (choice == 2) {
            list_tasks();
        } else if (choice == 3) {
            printf("Task ID: ");
            int id;
            scanf("%d", &id);
            complete_task(id);
        } else if (choice == 4) {
            save_tasks();
            free_all_tasks();
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}
