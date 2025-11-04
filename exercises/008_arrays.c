// Exercise 008: Arrays
//
// Arrays store multiple values of the same type in a sequence.
// Array indices start at 0!
//
// Declaration:
//   type name[size] = {value1, value2, ...};
//
// Access:
//   name[index]
//
// Fix the array access to print the third number (30)!
//
// EXPECTED: Third element: 30
// HINT: The third element is at index 2 (remember: arrays start at 0!)

#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};

    int third = numbers[3];  // TODO: Fix this index!

    printf("Third element: %d\n", third);
    return 0;
}
