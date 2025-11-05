// Exercise 003: Variables
//
// Variables are used to store data. In C, you must declare a variable's
// type before using it.
//
// Common types:
//   int    - integers (whole numbers)
//   float  - floating-point numbers (decimals)
//   char   - single characters
//
// Fix THREE variable-related bugs below!
//
// EXPECTED: The answer is 42
// EXPECTED: Pi is approximately 3.14
// EXPECTED: Grade: A
// HINT: Match variable types with their values and format specifiers

#include <stdio.h>

int main(void) {
    unknown answer = 42;  // TODO: Fix this type!

    int pi = 3.14;  // TODO: Fix this type!

    char grade = 'A';

    printf("The answer is %d\n", answer);
    printf("Pi is approximately %.2f\n", pi);  // TODO: Fix the variable type!
    printf("Grade: %c\n", grade);
    return 0;
}
