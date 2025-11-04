// Exercise 007: Functions
//
// Functions let you organize and reuse code. A function has:
//   - A return type (what it gives back)
//   - A name
//   - Parameters (inputs in parentheses)
//   - A body (code in braces)
//
// This function should add two numbers and return the result.
//
// EXPECTED: Sum: 30
// HINT: Use the + operator to add a and b, then return the result

#include <stdio.h>

int add(int a, int b) {
    // TODO: Calculate and return the sum of a and b
    return 0;
}

int main(void) {
    int result = add(10, 20);
    printf("Sum: %d\n", result);
    return 0;
}
