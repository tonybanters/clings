# Clings - Learn C by fixing tiny broken programs
# Inspired by Ziglings and Rustlings

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
BUILD_DIR = .build
PROGRESS_FILE = .progress.txt
ROGUE_PROGRESS = .rogue_progress
CASUAL_PROGRESS = .casual_progress
TUI_BIN = clings_tui

# Find all exercise files
EXERCISES := $(sort $(wildcard exercises/*.c))
EXERCISE_NUMS := $(patsubst exercises/%.c,%,$(EXERCISES))

# ANSI color codes
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[1;33m
BLUE := \033[0;34m
BOLD := \033[1m
RESET := \033[0m

.PHONY: all clean help run start reset hint rogue tui tui-rogue

all: sequential

help:
	@printf "$(BOLD)Clings - Learn C by fixing tiny broken programs$(RESET)\n"
	@printf "\n"
	@printf "Usage:\n"
	@printf "  $(GREEN)make$(RESET)           - Run exercises sequentially until one fails\n"
	@printf "  $(GREEN)make run N$(RESET)     - Run specific exercise N (e.g., make run 5)\n"
	@printf "  $(GREEN)make start N$(RESET)   - Start from exercise N onwards\n"
	@printf "  $(GREEN)make hint$(RESET)      - Show hint for the first failing exercise\n"
	@printf "  $(GREEN)make rogue$(RESET)     - Hardcore mode: restart from 1 on any failure\n"
	@printf "  $(GREEN)make tui$(RESET)       - Interactive TUI (casual mode - can retry failures)\n"
	@printf "  $(GREEN)make tui-rogue$(RESET) - Interactive TUI (rogue mode - restart on failure)\n"
	@printf "  $(GREEN)make reset$(RESET)     - Reset progress tracking\n"
	@printf "  $(GREEN)make clean$(RESET)     - Clean build artifacts\n"
	@printf "\n"

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Sequential mode - run until failure
sequential: $(BUILD_DIR)
	@printf "$(BOLD)$(BLUE)Starting Clings...$(RESET)\n"
	@printf "\n"
	@$(MAKE) -s run-all

run-all:
	@success=0; \
	total=0; \
	for exercise in $(EXERCISE_NUMS); do \
		total=$$((total + 1)); \
		if $(MAKE) -s run-single EXERCISE=$$exercise; then \
			success=$$((success + 1)); \
		else \
			printf "\n"; \
			printf "$(RED)$(BOLD)Exercise $$exercise failed!$(RESET)\n"; \
			printf "$(YELLOW)Fix the exercise and run 'make' again.$(RESET)\n"; \
			exit 1; \
		fi; \
	done; \
	printf "\n"; \
	printf "$(GREEN)$(BOLD)🎉 All $$total exercises completed!$(RESET)\n"; \
	printf "$(GREEN)You've mastered the basics of C programming!$(RESET)\n"

# Run specific exercise
run:
	@if [ -z "$(filter-out run,$(MAKECMDGOALS))" ]; then \
		printf "$(RED)Error: Please specify an exercise number$(RESET)\n"; \
		printf "Usage: make run N (e.g., make run 5)\n"; \
		exit 1; \
	fi
	@$(MAKE) -s run-single EXERCISE=$(filter-out run,$(MAKECMDGOALS))

# Start from specific exercise
start:
	@if [ -z "$(filter-out start,$(MAKECMDGOALS))" ]; then \
		printf "$(RED)Error: Please specify a starting exercise number$(RESET)\n"; \
		printf "Usage: make start N (e.g., make start 5)\n"; \
		exit 1; \
	fi
	@START_NUM=$(filter-out start,$(MAKECMDGOALS)); \
	for exercise in $(EXERCISE_NUMS); do \
		NUM=$$(echo $$exercise | sed 's/^0*\([0-9]*\).*/\1/'); \
		START=$$(echo $$START_NUM | sed 's/^0*\([0-9]*\).*/\1/'); \
		if [ "$$NUM" -ge "$$START" ] 2>/dev/null; then \
			if $(MAKE) -s run-single EXERCISE=$$exercise; then \
				continue; \
			else \
				printf "\n"; \
				printf "$(RED)$(BOLD)Exercise $$exercise failed!$(RESET)\n"; \
				printf "$(YELLOW)Fix the exercise and run 'make' again.$(RESET)\n"; \
				exit 1; \
			fi; \
		fi; \
	done; \
	printf "\n"; \
	printf "$(GREEN)$(BOLD)🎉 All exercises from $$START_NUM completed!$(RESET)\n"

# Run a single exercise (internal target)
run-single: $(BUILD_DIR)
	@if [ -z "$(EXERCISE)" ]; then \
		printf "$(RED)Error: EXERCISE not specified$(RESET)\n"; \
		exit 1; \
	fi
	@EXERCISE_FILE="exercises/$(EXERCISE).c"; \
	if [ ! -f "$$EXERCISE_FILE" ]; then \
		printf "$(RED)Error: Exercise $$EXERCISE_FILE not found$(RESET)\n"; \
		exit 1; \
	fi; \
	printf "$(BLUE)Compiling $(EXERCISE).c...$(RESET)\n"; \
	EXPECTED=$$(grep "// EXPECTED:" $$EXERCISE_FILE | sed 's|.*// EXPECTED: *||' | sed ':a;N;$$!ba;s/\n/\\n/g'); \
	if $(CC) $(CFLAGS) $$EXERCISE_FILE -o $(BUILD_DIR)/$(EXERCISE) 2>&1; then \
		printf "$(GREEN)✓ Compilation successful$(RESET)\n"; \
		if [ -n "$$EXPECTED" ]; then \
			printf "$(BLUE)Running $(EXERCISE)...$(RESET)\n"; \
			OUTPUT=$$($(BUILD_DIR)/$(EXERCISE) 2>&1); \
			OUTPUT_STRIPPED=$$(echo "$$OUTPUT" | sed 's/[[:space:]]*$$//'); \
			EXPECTED_STRIPPED=$$(printf "%b" "$$EXPECTED" | sed 's/[[:space:]]*$$//'); \
			if [ "$$OUTPUT_STRIPPED" = "$$EXPECTED_STRIPPED" ]; then \
				printf "$(GREEN)✓ Output correct$(RESET)\n"; \
				printf "$(GREEN)$(BOLD)Exercise $(EXERCISE) complete!$(RESET)\n"; \
				printf "\n"; \
				exit 0; \
			else \
				printf "$(RED)✗ Output incorrect$(RESET)\n"; \
				printf "$(YELLOW)Expected:$(RESET)\n"; \
				printf "%b\n" "$$EXPECTED"; \
				printf "$(YELLOW)Got:$(RESET)\n"; \
				echo "$$OUTPUT"; \
				exit 1; \
			fi; \
		else \
			printf "$(GREEN)$(BOLD)Exercise $(EXERCISE) complete!$(RESET)\n"; \
			printf "\n"; \
			exit 0; \
		fi; \
	else \
		printf "$(RED)✗ Compilation failed$(RESET)\n"; \
		exit 1; \
	fi

# Show hint for the first failing exercise
hint:
	@success=0; \
	for exercise in $(EXERCISE_NUMS); do \
		if ! $(MAKE) -s run-single EXERCISE=$$exercise 2>/dev/null; then \
			HINT_FILE=".hints/$$exercise.txt"; \
			if [ -f "$$HINT_FILE" ]; then \
				printf "$(YELLOW)$(BOLD)Hint for exercise $$exercise:$(RESET)\n"; \
				printf "$(YELLOW)"; \
				cat "$$HINT_FILE"; \
				printf "$(RESET)\n"; \
			else \
				printf "$(YELLOW)No hint available for exercise $$exercise yet$(RESET)\n"; \
			fi; \
			exit 0; \
		fi; \
	done; \
	printf "$(GREEN)All exercises are passing! No hint needed.$(RESET)\n"

# Rogue mode - restart from 1 on any failure
rogue: $(BUILD_DIR)
	@printf "$(BOLD)$(RED)== ROGUE MODE ACTIVATED ==$(RESET)\n"
	@printf "$(YELLOW)Fail once, start over from exercise 1!$(RESET)\n"
	@printf "\n"
	@if [ -f $(ROGUE_PROGRESS) ]; then \
		CURRENT=$$(cat $(ROGUE_PROGRESS)); \
		BEST=$$(echo $$CURRENT | cut -d'/' -f1); \
		printf "$(BLUE)Best run: $$BEST exercises cleared$(RESET)\n"; \
		printf "\n"; \
	fi
	@printf "$(YELLOW)Backing up exercises...$(RESET)\n"; \
	rm -rf .rogue_backup; \
	cp -r exercises .rogue_backup; \
	printf "$(GREEN)Ready!$(RESET)\n\n"; \
	while true; do \
		cleared=0; \
		total=$$(echo $(EXERCISE_NUMS) | wc -w); \
		failed=0; \
		for exercise in $(EXERCISE_NUMS); do \
			printf "$(BOLD)Progress: $$cleared/$$total$(RESET) | $(BLUE)Current: $$exercise$(RESET)\n"; \
			printf "$(YELLOW)Fix the exercise in exercises/$$exercise.c$(RESET)\n"; \
			printf "$(GREEN)Press Enter when ready to submit...$(RESET) "; \
			read ready; \
			printf "\n"; \
			if $(MAKE) -s run-single EXERCISE=$$exercise; then \
				cleared=$$((cleared + 1)); \
				printf "\n"; \
			else \
				printf "\n"; \
				printf "$(RED)$(BOLD)== GAME OVER ==$(RESET)\n"; \
				printf "$(RED)Exercise $$exercise failed!$(RESET)\n"; \
				printf "$(YELLOW)You cleared: $$cleared exercises$(RESET)\n"; \
				if [ -f $(ROGUE_PROGRESS) ]; then \
					BEST=$$(cat $(ROGUE_PROGRESS) | cut -d'/' -f1); \
					if [ $$cleared -gt $$BEST ]; then \
						printf "$(GREEN)$(BOLD)== NEW RECORD ==$(RESET)\n"; \
						printf "$(GREEN)Previous best: $$BEST$(RESET)\n"; \
						echo "$$cleared/$$total" > $(ROGUE_PROGRESS); \
					else \
						printf "$(BLUE)Best run: $$BEST exercises$(RESET)\n"; \
					fi; \
				else \
					echo "$$cleared/$$total" > $(ROGUE_PROGRESS); \
				fi; \
				printf "\n"; \
				printf "$(YELLOW)Restoring exercises from backup...$(RESET)\n"; \
				rm -rf exercises; \
				cp -r .rogue_backup exercises; \
				printf "$(RED)Restarting from exercise 1...$(RESET)\n"; \
				printf "$(GREEN)Press Enter to continue...$(RESET) "; \
				read ready; \
				printf "\n"; \
				failed=1; \
				break; \
			fi; \
		done; \
		if [ $$failed -eq 0 ]; then \
			printf "\n"; \
			printf "$(GREEN)$(BOLD)== VICTORY ==$(RESET)\n"; \
			printf "$(GREEN)You completed all $$total exercises in rogue mode!$(RESET)\n"; \
			printf "$(GREEN)$(BOLD)You are a C programming master!$(RESET)\n"; \
			echo "$$total/$$total" > $(ROGUE_PROGRESS); \
			rm -rf .rogue_backup; \
			break; \
		fi; \
	done

# TUI mode - casual mode (default) with interactive interface
tui: $(BUILD_DIR)
	@if [ ! -f $(TUI_BIN) ]; then \
		printf "$(YELLOW)Building TUI...$(RESET)\n"; \
		if $(CC) -o $(TUI_BIN) clings_tui.c -lncurses 2>/dev/null; then \
			: ; \
		else \
			NCURSES_INC=$$(find /nix/store -name "ncurses.h" 2>/dev/null | head -1 | xargs dirname 2>/dev/null); \
			NCURSES_LIB=$$(find /nix/store -path "*/ncurses-*/lib" -type d 2>/dev/null | head -1); \
			if [ -n "$$NCURSES_INC" ] && [ -n "$$NCURSES_LIB" ]; then \
				$(CC) -o $(TUI_BIN) clings_tui.c -I$$NCURSES_INC -L$$NCURSES_LIB -lncurses; \
			else \
				printf "$(RED)Error: ncurses not found. Try running 'nix develop' first.$(RESET)\n"; \
				exit 1; \
			fi; \
		fi; \
	fi
	@./$(TUI_BIN)

# TUI mode - rogue mode with interactive interface
tui-rogue: $(BUILD_DIR)
	@if [ ! -f $(TUI_BIN) ]; then \
		printf "$(YELLOW)Building TUI...$(RESET)\n"; \
		if $(CC) -o $(TUI_BIN) clings_tui.c -lncurses 2>/dev/null; then \
			: ; \
		else \
			NCURSES_INC=$$(find /nix/store -name "ncurses.h" 2>/dev/null | head -1 | xargs dirname 2>/dev/null); \
			NCURSES_LIB=$$(find /nix/store -path "*/ncurses-*/lib" -type d 2>/dev/null | head -1); \
			if [ -n "$$NCURSES_INC" ] && [ -n "$$NCURSES_LIB" ]; then \
				$(CC) -o $(TUI_BIN) clings_tui.c -I$$NCURSES_INC -L$$NCURSES_LIB -lncurses; \
			else \
				printf "$(RED)Error: ncurses not found. Try running 'nix develop' first.$(RESET)\n"; \
				exit 1; \
			fi; \
		fi; \
	fi
	@./$(TUI_BIN) rogue

# Reset progress
reset:
	@rm -f $(PROGRESS_FILE) $(ROGUE_PROGRESS) $(CASUAL_PROGRESS)
	@printf "$(GREEN)Progress reset!$(RESET)\n"

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR) .rogue_backup .casual_backup $(TUI_BIN)
	@printf "$(GREEN)Build artifacts cleaned!$(RESET)\n"

# Allow numeric arguments to be passed as targets
%:
	@:
