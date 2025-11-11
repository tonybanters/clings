// Exercise 021: Double Pointers (Pointers to Pointers)
//
// A pointer can point to anything, including another pointer!
//
// Declaration:
//   int x = 42;
//   int *ptr = &x;       // ptr points to x
//   int **ptr2 = &ptr;   // ptr2 points to ptr (which points to x)
//
// Access:
//   *ptr2 gives you ptr
//   **ptr2 gives you x (the final value)
//
// Double pointers are commonly used for:
//   - Arrays of strings (char **)
//   - Functions that need to modify pointers
//   - Dynamic 2D arrays
//
// Fix THREE double pointer bugs!
//
// EXPECTED: Value: 42
// EXPECTED: Via single pointer: 42
// EXPECTED: Via double pointer: 42
// EXPECTED: Modified value: 100
// HINT: Use * for single dereference, ** for double dereference

#include <stdio.h>

void modify_via_pointer(int *ptr) {
    ptr = 100;  // TODO: Fix this!
}

int main(void) {
    int value = 42;
    int *ptr = &value;
    int **ptr2 = ptr;  // TODO: Fix this!

    printf("Value: %d\n", value);
    printf("Via single pointer: %d\n", *ptr);
    printf("Via double pointer: %d\n", *ptr2);  // TODO: Fix this!

    modify_via_pointer(&value);
    printf("Modified value: %d\n", value);

    return 0;
}
