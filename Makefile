# Clings - Learn C by fixing tiny broken programs
# Inspired by Ziglings and Rustlings

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
BUILD_DIR = .build
PROGRESS_FILE = .progress.txt

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

.PHONY: all clean help run start reset

all: sequential

help:
	@printf "$(BOLD)Clings - Learn C by fixing tiny broken programs$(RESET)\n"
	@printf "\n"
	@printf "Usage:\n"
	@printf "  $(GREEN)make$(RESET)           - Run exercises sequentially until one fails\n"
	@printf "  $(GREEN)make run N$(RESET)     - Run specific exercise N (e.g., make run 5)\n"
	@printf "  $(GREEN)make start N$(RESET)   - Start from exercise N onwards\n"
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
			if [ "$$OUTPUT" = "$$(printf "%b" "$$EXPECTED")" ]; then \
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
				HINT=$$(grep "// HINT:" $$EXERCISE_FILE | sed 's/.*HINT: *//'); \
				if [ -n "$$HINT" ]; then \
					printf "$(YELLOW)Hint: $$HINT$(RESET)\n"; \
				fi; \
				exit 1; \
			fi; \
		else \
			printf "$(GREEN)$(BOLD)Exercise $(EXERCISE) complete!$(RESET)\n"; \
			printf "\n"; \
			exit 0; \
		fi; \
	else \
		printf "$(RED)✗ Compilation failed$(RESET)\n"; \
		HINT=$$(grep "// HINT:" $$EXERCISE_FILE | sed 's/.*HINT: *//'); \
		if [ -n "$$HINT" ]; then \
			printf "$(YELLOW)Hint: $$HINT$(RESET)\n"; \
		fi; \
		exit 1; \
	fi

# Reset progress
reset:
	@rm -f $(PROGRESS_FILE)
	@printf "$(GREEN)Progress reset!$(RESET)\n"

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)
	@printf "$(GREEN)Build artifacts cleaned!$(RESET)\n"

# Allow numeric arguments to be passed as targets
%:
	@:
