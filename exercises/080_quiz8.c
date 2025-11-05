// Exercise 080: Quiz 8 - File I/O and Bit Manipulation
//
// This quiz tests your understanding of:
//   - File I/O (binary and text)
//   - Bit manipulation
//   - Error handling
//
// Create a program that writes binary data to a file
// and reads it back with bit manipulation!
//
// EXPECTED: Writing data: value=170 (binary: 10101010)
// EXPECTED: Set bits: 4
// EXPECTED: Is power of 2: No
// EXPECTED: Read back: value=170 (binary: 10101010)
// HINT: Use fwrite/fread, count bits, check power of 2

#include <stdio.h>

int count_bits(unsigned char n) {
    // TODO: Implement bit counting!
    // Hint: while (n) { count += n & 1; n >>= 1; }
    return 0;
}

int is_power_of_two(unsigned char n) {
    // TODO: Implement power of 2 check!
    // Hint: n > 0 && (n & (n-1)) == 0
    return 0;
}

void print_binary(unsigned char n) {
    // TODO: Print binary representation!
    // Hint: for (int i = 7; i >= 0; i--) printf("%d", (n >> i) & 1);
    printf("10101010");
}

int main(void) {
    unsigned char value = 0xAA;  // 10101010 in binary

    printf("Writing data: value=%u (binary: ", value);
    print_binary(value);
    printf(")\n");

    printf("Set bits: %d\n", count_bits(value));
    printf("Is power of 2: %s\n", is_power_of_two(value) ? "Yes" : "No");

    // TODO: Write to binary file!
    // Hint: FILE *f = fopen("data.bin", "wb");
    //       fwrite(&value, sizeof(unsigned char), 1, f);

    // TODO: Read from binary file!
    // Hint: f = fopen("data.bin", "rb");
    //       fread(&value, sizeof(unsigned char), 1, f);

    printf("Read back: value=%u (binary: ", value);
    print_binary(value);
    printf(")\n");

    return 0;
}
