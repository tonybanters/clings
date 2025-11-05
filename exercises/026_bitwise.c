// Exercise 026: Bitwise Operations
//
// Bitwise operators work on individual bits:
//   &   AND     - both bits must be 1
//   |   OR      - at least one bit must be 1
//   ^   XOR     - bits must be different
//   ~   NOT     - flip all bits
//   <<  Left shift  - shift bits left (multiply by 2)
//   >>  Right shift - shift bits right (divide by 2)
//
// Common uses:
//   - Flags and permissions
//   - Fast math (multiply/divide by powers of 2)
//   - Bit manipulation
//   - Low-level hardware control
//
// Fix THREE bitwise operation bugs!
//
// EXPECTED: a & b = 0 (binary: 0000)
// EXPECTED: a | b = 15 (binary: 1111)
// EXPECTED: a ^ b = 15 (binary: 1111)
// EXPECTED: ~a = -13 (binary: 11110011...)
// EXPECTED: a << 1 = 24 (multiply by 2)
// EXPECTED: b >> 1 = 1 (divide by 2)
// EXPECTED: Flags: READ and EXECUTE enabled
// HINT: Understand bit patterns, fix operators, check flag logic

#include <stdio.h>

// Flag definitions (powers of 2)
#define READ    1  // 0001
#define WRITE   2  // 0010
#define EXECUTE 4  // 0100
#define DELETE  8  // 1000

int main(void) {
    unsigned int a = 12;  // binary: 1100
    unsigned int b = 3;   // binary: 0011

    printf("a & b = %u (binary: ", a & b);
    for (int i = 3; i >= 0; i--) {
        printf("%d", (a & b) >> i & 1);
    }
    printf(")\n");

    printf("a | b = %u (binary: ", a | b);
    for (int i = 3; i >= 0; i--) {
        printf("%d", (a | b) >> i & 1);
    }
    printf(")\n");

    printf("a ^ b = %u (binary: ", a ^ b);
    for (int i = 3; i >= 0; i--) {
        printf("%d", (a ^ b) >> i & 1);
    }
    printf(")\n");

    printf("~a = %d (binary: 11110011...)\n", (signed int)~a);

    // TODO: Fix - should be left shift (<<), not right shift!
    printf("a << 1 = %u (multiply by 2)\n", a >> 1);

    printf("b >> 1 = %u (divide by 2)\n", b >> 1);

    // Using bitwise OR to set flags
    unsigned int permissions = READ & EXECUTE;  // TODO: Fix - should use OR (|) to combine flags!

    printf("Flags: ");
    if (permissions & READ) {
        printf("READ ");
    }
    if (permissions & WRITE) {
        printf("WRITE ");
    }
    if (permissions & EXECUTE) {
        printf("EXECUTE ");
    }
    // TODO: Fix - missing logic to check DELETE flag!
    printf("enabled\n");

    return 0;
}
