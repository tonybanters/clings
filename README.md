# Clings

Welcome to **Clings** - a series of tiny broken C programs that will teach you how to read and write C code!

Inspired by the brilliant [Ziglings](https://codeberg.org/ziglings/exercises) and [Rustlings](https://github.com/rust-lang/rustlings) projects.

## Getting Started

### Prerequisites

- A C compiler (GCC or Clang recommended)
- Make
- Basic command-line knowledge

### Installation

```bash
git clone <repository-url> clings
cd clings
```

### Usage

The simplest way to get started:

```bash
make
```

This will run through each exercise in order, compiling and testing them. When an exercise fails, you'll see the error and can fix it. Once fixed, run `make` again to continue.

### Other Commands

```bash
make run 5      # Run a specific exercise (e.g., exercise 5)
make start 10   # Start from exercise 10 and continue sequentially
make clean      # Remove build artifacts
make help       # Show help message
```

## How It Works

Each exercise is a small C program with intentional bugs or missing code. Your job is to fix them!

1. Run `make` to start
2. Read the compilation errors or test failures
3. Open the exercise file and fix the problems
4. Run `make` again
5. Repeat until all exercises pass!

## Exercise Format

Each exercise contains:

- **Comments** explaining the concept being taught
- **Intentional bugs** for you to fix (marked with `TODO` or `FIX`)
- **Expected output** (as a comment: `// EXPECTED: ...`)
- **Hints** when you get stuck (as a comment: `// HINT: ...`)

Example:

```c
// Exercise 001: Hello World
// EXPECTED: Hello, Clings!
// HINT: Check the string in printf!

#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");  // TODO: Fix this message
    return 0;
}
```

## What You'll Learn

Clings covers modern C (C99/C11) including:

- **Basics**: Variables, operators, control flow, functions
- **Pointers & Arrays**: Pointer arithmetic, arrays, strings
- **Memory Management**: malloc, free, memory leaks, valgrind
- **Structs & Unions**: Complex data types, alignment
- **File I/O**: Reading and writing files, error handling
- **Preprocessor**: Macros, conditional compilation
- **Standard Library**: Deep dive into stdlib, string.h, stdio.h
- **Security**: Buffer overflows, common vulnerabilities, best practices
- **Build Tools**: Makefiles, compilation flags, linking

## Philosophy

Like Ziglings, Clings aims to:

- Be self-contained and self-explanatory
- Teach by doing, not by reading
- Provide immediate feedback
- Make learning C fun and engaging
- Require no prior systems programming experience

## License

GPL

## Acknowledgments

- [Ziglings](https://codeberg.org/ziglings/exercises) by Dave Gauer
- [Rustlings](https://github.com/rust-lang/rustlings) by the Rust Team
- The C programming community

---

Ready to begin? Run `make` and start learning C.
