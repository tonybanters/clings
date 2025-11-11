// Exercise 073: File Seeking
//
// Move around in a file with fseek()!
//
// fseek(file, offset, whence) where whence is:
//   SEEK_SET: from beginning
//   SEEK_CUR: from current position
//   SEEK_END: from end
//
// ftell() returns current position!
//
// EXPECTED: File size: 15 bytes
// EXPECTED: Last 5 bytes: World
// EXPECTED: First 5 bytes: Hello
// HINT: Use SEEK_END to find size, SEEK_SET to reposition

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("message.txt", "w+");
    if (file == NULL) return 1;

    fprintf(file, "Hello, World!!!");

    // Find file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    printf("File size: %ld bytes\n", size);

    // Read last 5 bytes
    // TODO: Fix this!
    fseek(file, 5, SEEK_SET);
    char buffer[6];
    fread(buffer, 1, 5, file);
    buffer[5] = '\0';
    printf("Last 5 bytes: %s\n", buffer);

    // Read first 5 bytes
    // TODO: Seek back to beginning!
    // fseek(file, 0, SEEK_SET);
    fread(buffer, 1, 5, file);
    buffer[5] = '\0';
    printf("First 5 bytes: %s\n", buffer);

    fclose(file);
    return 0;
}
