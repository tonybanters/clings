// Exercise 071: File Copy Program
//
// Copy one file to another byte by byte!
//
// Important: Always check fopen return value!
//
// EXPECTED: Copying test.txt to test_copy.txt...
// EXPECTED: File copied successfully!
// HINT: Use fgetc/fputc for byte-by-byte copy, check for EOF

#include <stdio.h>

int main(void) {
    FILE *source = fopen("test.txt", "r");
    FILE *dest = fopen("test_copy.txt", "w");

    // TODO: Check if files opened successfully!
    // if (source == NULL || dest == NULL) { ... }

    printf("Copying test.txt to test_copy.txt...\n");

    int ch;
    // TODO: Fix - should be != EOF, not == EOF!
    while ((ch = fgetc(source)) == EOF) {
        fputc(ch, dest);
    }

    // TODO: Don't forget to close both files!

    printf("File copied successfully!\n");
    return 0;
}
