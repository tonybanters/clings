// Exercise 027: Command Line Arguments (argc, argv)
//
// Programs can receive arguments from the command line:
//
// int main(int argc, char *argv[]) {
//     // argc = argument count (includes program name)
//     // argv = argument vector (array of strings)
//     // argv[0] = program name
//     // argv[1] = first argument
//     // argv[argc] = NULL
// }
//
// Example:
//   ./program hello world
//   argc = 3
//   argv[0] = "./program"
//   argv[1] = "hello"
//   argv[2] = "world"
//
// Fix THREE command-line argument bugs!
//
// EXPECTED: Program name: ./027_argc_argv
// EXPECTED: Number of arguments: 2
// EXPECTED: Argument 1: hello
// EXPECTED: Argument 2: world
// HINT: Remember argc includes program name, arrays start at 0, check bounds

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    printf("Program name: %s\n", argv[0]);

    // TODO: Fix this!
    printf("Number of arguments: %d\n", argc);

    // Check if we have at least 2 arguments (plus program name)
    if (argc < 3) {
        printf("Usage: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }

    // Print arguments
    // TODO: Fix this!
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // Check for specific argument
    int found = 0;
    for (int i = 1; i < argc; i++) {
        // TODO: Fix this!
        if (argv[i] == "hello") {
            found = 1;
            break;
        }
    }

    return 0;
}
