// Exercise 007: Functions
//
// Functions let you organize and reuse code. A function has:
//   - A return type (what it gives back)
//   - A name
//   - Parameters (inputs in parentheses)
//   - A body (code in braces)
//
// Functions must be declared before they're used. You can:
//   1. Define the function before main()
//   2. Use a function prototype (declaration) at the top
//
// Fix THREE bugs related to functions!
//
// EXPECTED: Sum: 30
// EXPECTED: Product: 200
// EXPECTED: Max: 20
// HINT: Check function implementations, return types, and declarations

#include <stdio.h>

// Function prototypes
int add(int a, int b);
int multiply(int a, int b);
void max(int a, int b);  // TODO: Fix the return type!

int add(int a, int b) {
    // TODO: Calculate and return the sum of a and b
    return 0;
}

int multiply(int a, int b) {
    int result = a * b;
    // TODO: Don't forget to return the result!
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    printf("Sum: %d\n", add(10, 20));
    printf("Product: %d\n", multiply(10, 20));
    printf("Max: %d\n", max(15, 20));
    return 0;
}
