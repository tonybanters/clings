// Exercise 048: File Writing and Appending
//
// File modes:
//   "r"  - read (must exist)
//   "w"  - write (creates/truncates)
//   "a"  - append (creates/adds to end)
//   "r+" - read and write (must exist)
//   "w+" - read and write (creates/truncates)
//   "a+" - read and append
//
// Functions:
//   fprintf() - formatted write
//   fputs()   - write string
//   fputc()   - write character
//   fwrite()  - write binary data
//
// Always:
//   - Check if fopen returns NULL
//   - Close files with fclose()
//   - Flush with fflush() if needed
//
// Fix THREE file writing bugs!
//
// EXPECTED: Written to file: data.txt
// EXPECTED: Appended to file: data.txt
// EXPECTED: Final contents:
// EXPECTED: Line 1: Hello
// EXPECTED: Line 2: World
// EXPECTED: Line 3: Appended
// HINT: Use correct modes, close files before reopening, check errors

#include <stdio.h>

int main(void) {
    FILE *file;

    // Write initial content
    // TODO: Fix - should use "w" mode for writing!
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return 1;
    }

    fprintf(file, "Line 1: Hello\n");
    fprintf(file, "Line 2: World\n");
    fclose(file);

    printf("Written to file: data.txt\n");

    // Append more content
    file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("Failed to open file for appending\n");
        return 1;
    }

    // TODO: Fix - missing newline in fprintf!
    fprintf(file, "Line 3: Appended");
    fclose(file);

    printf("Appended to file: data.txt\n");

    // Read and display contents
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }

    printf("Final contents:\n");
    char buffer[100];
    // TODO: Fix - while should check != NULL, not == NULL!
    while (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
