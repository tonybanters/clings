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
// You can also use loops to process arrays!
//
// Fix THREE array-related bugs!
//
// EXPECTED: First: 10, Third: 30, Last: 50
// EXPECTED: Sum of all elements: 150
// EXPECTED: Array contents: 10 20 30 40 50
// HINT: Remember arrays are zero-indexed, and use array size carefully

#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};

    // Access individual elements
    int first = numbers[0];
    int third = numbers[3];  // TODO: Fix this index!
    int last = numbers[5];   // TODO: Fix this index!

    printf("First: %d, Third: %d, Last: %d\n", first, third, last);

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    printf("Sum of all elements: %d\n", sum);

    // Print all elements
    printf("Array contents: ");
    for (int i = 0; i <= 5; i++) {  // TODO: Fix the loop condition!
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
