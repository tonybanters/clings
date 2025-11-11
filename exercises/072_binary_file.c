// Exercise 072: Binary File I/O
//
// Write and read binary data (not text)!
//
// fread/fwrite work with raw bytes:
//   fwrite(ptr, size, count, file)
//   fread(ptr, size, count, file)
//
// EXPECTED: Writing binary data...
// EXPECTED: Read back: 42 -17 3.14
// HINT: Use "wb" and "rb" modes, fwrite/fread with sizeof

#include <stdio.h>

int main(void) {
    // Write binary data
    FILE *file = fopen("data.bin", "wb");
    if (file == NULL) return 1;

    int num1 = 42;
    short num2 = -17;
    float num3 = 3.14f;

    printf("Writing binary data...\n");

    fwrite(&num1, sizeof(int), 1, file);
    fwrite(&num2, sizeof(short), 1, file);
    // TODO: Fix this!
    fwrite(num3, sizeof(float), 1, file);

    fclose(file);

    // Read binary data
    // TODO: Fix this!
    file = fopen("data.bin", "r");
    if (file == NULL) return 1;

    int r1;
    short r2;
    float r3;

    fread(&r1, sizeof(int), 1, file);
    fread(&r2, sizeof(short), 1, file);
    fread(&r3, sizeof(float), 1, file);

    printf("Read back: %d %d %.2f\n", r1, r2, r3);

    // TODO: Don't forget to close the file!

    return 0;
}
