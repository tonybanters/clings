// Exercise 019: File I/O - Reading and Writing
//
// C provides file operations through stdio.h:
//   fopen()  - opens a file
//   fclose() - closes a file
//   fgetc()  - reads a character
//   fgets()  - reads a line
//   fprintf()- writes formatted text
//
// Modes:
//   "r"  - read (file must exist)
//   "w"  - write (creates or truncates file)
//   "a"  - append (creates or adds to end)
//   "r+" - read and write
//
// Always check if fopen returns NULL!
// Always close files with fclose()!
//
// Fix THREE file I/O bugs!
//
// EXPECTED: Writing to file...
// EXPECTED: Reading from file:
// EXPECTED: Line 1: Hello from file!
// EXPECTED: Line 2: This is line 2
// EXPECTED: Line 3: And line 3!
// HINT: Fix file modes, check for errors, and handle file operations correctly

#include <stdio.h>

int main(void) {
    // First, create and write to a file
    printf("Writing to file...\n");
    FILE *file = fopen("test.txt", "r");  // TODO: Fix - should be write mode "w"!

    if (file == NULL) {
        printf("Could not create file\n");
        return 1;
    }

    fprintf(file, "Hello from file!\n");
    fprintf(file, "This is line 2\n");
    fprintf(file, "And line 3!\n");
    // TODO: Missing fclose() here! Always close before reopening!

    // Now read it back line by line
    printf("Reading from file:\n");
    file = fopen("test.txt", "w");  // TODO: Fix - should be read mode "r"!
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char buffer[100];
    int line_num = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Line %d: %s", line_num, buffer);
        line_num++;
    }

    fclose(file);
    return 0;
}
