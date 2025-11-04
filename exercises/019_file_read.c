// Exercise 019: File I/O - Reading
//
// C provides file operations through stdio.h:
//   fopen()  - opens a file
//   fclose() - closes a file
//   fgetc()  - reads a character
//   fgets()  - reads a line
//
// Modes:
//   "r"  - read
//   "w"  - write
//   "a"  - append
//
// Always check if fopen returns NULL (file not found)!
// Always close files with fclose()!
//
// This program tries to read from a file it creates first.
//
// HINT: Fix the fopen mode to write mode ("w")

#include <stdio.h>

int main(void) {
    // First, create a file
    FILE *file = fopen("test.txt", "r");  // TODO: Fix - should be write mode!

    if (file == NULL) {
        printf("Could not create file\n");
        return 1;
    }

    fprintf(file, "Hello from file!\n");
    fclose(file);

    // Now read it back
    file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
