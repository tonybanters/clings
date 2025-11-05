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
	@echo -e "$(BOLD)Clings - Learn C by fixing tiny broken programs$(RESET)"
	@echo -e ""
	@echo -e "Usage:"
	@echo -e "  $(GREEN)make$(RESET)           - Run exercises sequentially until one fails"
	@echo -e "  $(GREEN)make run N$(RESET)     - Run specific exercise N (e.g., make run 5)"
	@echo -e "  $(GREEN)make start N$(RESET)   - Start from exercise N onwards"
	@echo -e "  $(GREEN)make reset$(RESET)     - Reset progress tracking"
	@echo -e "  $(GREEN)make clean$(RESET)     - Clean build artifacts"
	@echo -e ""

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Sequential mode - run until failure
sequential: $(BUILD_DIR)
	@echo -e "$(BOLD)$(BLUE)Starting Clings...$(RESET)"
	@echo -e ""
	@$(MAKE) -s run-all

run-all:
	@success=0; \
	total=0; \
	for exercise in $(EXERCISE_NUMS); do \
		total=$$((total + 1)); \
		if $(MAKE) -s run-single EXERCISE=$$exercise; then \
			success=$$((success + 1)); \
		else \
			echo -e ""; \
			echo -e "$(RED)$(BOLD)Exercise $$exercise failed!$(RESET)"; \
			echo -e "$(YELLOW)Fix the exercise and run 'make' again.$(RESET)"; \
			exit 1; \
		fi; \
	done; \
	echo -e ""; \
	echo -e "$(GREEN)$(BOLD)🎉 All $$total exercises completed!$(RESET)"; \
	echo -e "$(GREEN)You've mastered the basics of C programming!$(RESET)"

# Run specific exercise
run:
	@if [ -z "$(filter-out run,$(MAKECMDGOALS))" ]; then \
		echo -e "$(RED)Error: Please specify an exercise number$(RESET)"; \
		echo -e "Usage: make run N (e.g., make run 5)"; \
		exit 1; \
	fi
	@$(MAKE) -s run-single EXERCISE=$(filter-out run,$(MAKECMDGOALS))

# Start from specific exercise
start:
	@if [ -z "$(filter-out start,$(MAKECMDGOALS))" ]; then \
		echo -e "$(RED)Error: Please specify a starting exercise number$(RESET)"; \
		echo -e "Usage: make start N (e.g., make start 5)"; \
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
				echo -e ""; \
				echo -e "$(RED)$(BOLD)Exercise $$exercise failed!$(RESET)"; \
				echo -e "$(YELLOW)Fix the exercise and run 'make' again.$(RESET)"; \
				exit 1; \
			fi; \
		fi; \
	done; \
	echo -e ""; \
	echo -e "$(GREEN)$(BOLD)🎉 All exercises from $$START_NUM completed!$(RESET)"

# Run a single exercise (internal target)
run-single: $(BUILD_DIR)
	@if [ -z "$(EXERCISE)" ]; then \
		echo -e "$(RED)Error: EXERCISE not specified$(RESET)"; \
		exit 1; \
	fi
	@EXERCISE_FILE="exercises/$(EXERCISE).c"; \
	if [ ! -f "$$EXERCISE_FILE" ]; then \
		echo -e "$(RED)Error: Exercise $$EXERCISE_FILE not found$(RESET)"; \
		exit 1; \
	fi; \
	echo -e "$(BLUE)Compiling $(EXERCISE).c...$(RESET)"; \
	EXPECTED=$$(grep "// EXPECTED:" $$EXERCISE_FILE | sed 's|.*// EXPECTED: *||' | sed ':a;N;$$!ba;s/\n/\\n/g'); \
	if $(CC) $(CFLAGS) $$EXERCISE_FILE -o $(BUILD_DIR)/$(EXERCISE) 2>&1; then \
		echo -e "$(GREEN)✓ Compilation successful$(RESET)"; \
		if [ -n "$$EXPECTED" ]; then \
			echo -e "$(BLUE)Running $(EXERCISE)...$(RESET)"; \
			OUTPUT=$$($(BUILD_DIR)/$(EXERCISE) 2>&1); \
			if [ "$$OUTPUT" = "$$(echo -e "$$EXPECTED")" ]; then \
				echo -e "$(GREEN)✓ Output correct$(RESET)"; \
				echo -e "$(GREEN)$(BOLD)Exercise $(EXERCISE) complete!$(RESET)"; \
				echo -e ""; \
				exit 0; \
			else \
				echo -e "$(RED)✗ Output incorrect$(RESET)"; \
				echo -e "$(YELLOW)Expected:$(RESET)"; \
				echo -e "$$(echo -e "$$EXPECTED")"; \
				echo -e "$(YELLOW)Got:$(RESET)"; \
				echo "$$OUTPUT"; \
				HINT=$$(grep "// HINT:" $$EXERCISE_FILE | sed 's/.*HINT: *//'); \
				if [ -n "$$HINT" ]; then \
					echo -e "$(YELLOW)Hint: $$HINT$(RESET)"; \
				fi; \
				exit 1; \
			fi; \
		else \
			echo -e "$(GREEN)$(BOLD)Exercise $(EXERCISE) complete!$(RESET)"; \
			echo -e ""; \
			exit 0; \
		fi; \
	else \
		echo -e "$(RED)✗ Compilation failed$(RESET)"; \
		HINT=$$(grep "// HINT:" $$EXERCISE_FILE | sed 's/.*HINT: *//'); \
		if [ -n "$$HINT" ]; then \
			echo -e "$(YELLOW)Hint: $$HINT$(RESET)"; \
		fi; \
		exit 1; \
	fi

# Reset progress
reset:
	@rm -f $(PROGRESS_FILE)
	@echo -e "$(GREEN)Progress reset!$(RESET)"

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)
	@echo -e "$(GREEN)Build artifacts cleaned!$(RESET)"

# Allow numeric arguments to be passed as targets
%:
	@:
