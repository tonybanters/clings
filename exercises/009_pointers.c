// Exercise 009: Pointers - Introduction
//
// Pointers are variables that store memory addresses.
// They're one of the most important features in C!
//
// Declaration:
//   int *ptr;   // ptr is a pointer to an int
//
// Address-of operator (&):
//   &variable   // gets the address of a variable
//
// Dereference operator (*):
//   *ptr        // gets the value at the address
//
// Pointers can also be used to modify values!
//
// Fix THREE pointer-related bugs!
//
// EXPECTED: Original: 42
// EXPECTED: Via pointer: 42
// EXPECTED: After modification: 100
// HINT: Use & to get addresses, * to dereference, and pointers can modify values

#include <stdio.h>

int main(void) {
    int value = 42;
    int *ptr;

    ptr = value;  // TODO: Fix this - we need the ADDRESS of value!

    printf("Original: %d\n", value);
    printf("Via pointer: %d\n", ptr);  // TODO: Fix this!

    // Modify value through pointer
    ptr = 100;  // TODO: Fix this!

    printf("After modification: %d\n", value);
    return 0;
}
