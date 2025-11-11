// Exercise 084: Simple Calculator
//
// Parse and evaluate simple expressions like "10 + 5"!
//
// EXPECTED: 10 + 5 = 15
// EXPECTED: 20 - 8 = 12
// EXPECTED: 6 * 7 = 42
// EXPECTED: 15 / 3 = 5
// HINT: Use sscanf to parse, switch for operations

#include <stdio.h>

int calculate(const char *expr) {
    int a, b;
    char op;

    // TODO: Fix this!
    sscanf(expr, "%d %d %d", &a, &op, &b);

    // TODO: Implement switch statement!
    // Hint: switch(op) { case '+': return a + b; ... }
    return 0;
}

int main(void) {
    printf("10 + 5 = %d\n", calculate("10 + 5"));
    printf("20 - 8 = %d\n", calculate("20 - 8"));
    printf("6 * 7 = %d\n", calculate("6 * 7"));
    // TODO: Fix this!
    printf("15 / 3 = %d\n", calculate("15 * 3"));

    return 0;
}
