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
// Fix the pointer operations below!
//
// EXPECTED: Value: 42, Address value: 42
// HINT: Use & to get the address, and * to get the value

#include <stdio.h>

int main(void) {
    int value = 42;
    int *ptr;

    ptr = value;  // TODO: Fix this - we need the ADDRESS of value!

    printf("Value: %d, Address value: %d\n", value, ptr);  // TODO: Fix - dereference ptr!
    return 0;
}
