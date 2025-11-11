// Exercise 081: Command Line Arguments
//
// Access arguments passed to your program!
//
// int main(int argc, char *argv[])
//   argc = argument count
//   argv = array of argument strings
//   argv[0] = program name
//
// EXPECTED: Program name: ./081_command_line_args
// EXPECTED: Number of arguments: 3
// EXPECTED: Arguments:
// EXPECTED:   hello
// EXPECTED:   world
// EXPECTED:   123
// HINT: Loop from 1 to argc (skip argv[0])

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);

    // TODO: Fix this!
    printf("Number of arguments: %d\n", argc);

    printf("Arguments:\n");
    // TODO: Fix this!
    for (int i = 0; i < argc; i++) {
        printf("  %s\n", argv[i]);
    }

    return 0;
}
