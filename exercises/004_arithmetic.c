// Exercise 004: Arithmetic
//
// C supports the standard arithmetic operators:
//   +  addition
//   -  subtraction
//   *  multiplication
//   /  division
//   %  modulo (remainder)
//
// Fix THREE arithmetic bugs to get the correct output!
//
// EXPECTED: Sum: 15
// EXPECTED: Product: 50
// EXPECTED: Remainder: 2
// HINT: Check the operations and variable values carefully

#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 5;
    int sum = a - b;  // TODO: Fix this operation!

    int x = 10;
    int y = 6;  // TODO: Fix this value to get product = 50!
    int product = x * y;

    int dividend = 17;
    int divisor = 5;
    int remainder = dividend / divisor;  // TODO: Fix this operator!

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Remainder: %d\n", remainder);
    return 0;
}
