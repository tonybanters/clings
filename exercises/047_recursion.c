// Exercise 047: Recursion - Basics
//
// Recursion is when a function calls itself.
//
// Requirements:
//   1. Base case - stops recursion
//   2. Recursive case - calls itself with simpler input
//   3. Progress toward base case
//
// Example - Factorial:
//   factorial(n) = n * factorial(n-1)
//   factorial(0) = 1  (base case)
//
// Stack depth matters! Too many recursive calls = stack overflow
//
// Common uses:
//   - Tree traversal
//   - Divide and conquer
//   - Mathematical sequences
//   - Backtracking
//
// Fix THREE recursion bugs!
//
// EXPECTED: Factorial of 5: 120
// EXPECTED: Fibonacci(7): 13
// EXPECTED: Sum 1 to 10: 55
// EXPECTED: Power 2^10: 1024
// HINT: Add base cases, fix recursive calls, ensure progress

#include <stdio.h>

int factorial(int n) {
    // TODO: Add base case - if n <= 1, return 1!
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    // TODO: Fix - should be fib(n-1) + fib(n-2), not multiply!
    return fibonacci(n - 1) * fibonacci(n - 2);
}

int sum_to_n(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum_to_n(n - 1);
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    // TODO: Fix - should multiply by base, not add!
    return base + power(base, exp - 1);
}

int main(void) {
    printf("Factorial of 5: %d\n", factorial(5));
    printf("Fibonacci(7): %d\n", fibonacci(7));
    printf("Sum 1 to 10: %d\n", sum_to_n(10));
    printf("Power 2^10: %d\n", power(2, 10));

    return 0;
}
