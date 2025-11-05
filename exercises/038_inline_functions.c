// Exercise 038: Inline Functions and Macros
//
// inline suggests compiler to inline function (C99).
//
// Inline vs Macro:
//   Inline function:
//     - Type-safe
//     - Debuggable
//     - Suggestion to compiler
//
//   Macro:
//     - Text replacement
//     - No type checking
//     - Can have side effects!
//
// Example macro pitfall:
//   #define SQUARE(x) x * x
//   SQUARE(1 + 2)  // expands to: 1 + 2 * 1 + 2 = 5 (wrong!)
//
// Fix THREE macro/inline bugs!
//
// EXPECTED: Inline max: 20
// EXPECTED: Macro SQUARE(5): 25
// EXPECTED: Macro SQUARE(1+2): 9
// EXPECTED: Safe SQUARE(1+2): 9
// HINT: Use parentheses in macros, understand expansion, fix side effects

#include <stdio.h>

// Inline function (C99)
inline int max_inline(int a, int b) {
    return (a > b) ? a : b;
}

// Dangerous macro without parentheses!
// TODO: Fix - need parentheses around x!
#define SQUARE(x) x * x

// Safe macro with parentheses
#define SAFE_SQUARE(x) ((x) * (x))

// Macro with side effect bug
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    int x = 10, y = 20;

    // Inline function
    printf("Inline max: %d\n", max_inline(x, y));

    // Macro pitfall
    printf("Macro SQUARE(5): %d\n", SQUARE(5));
    // TODO: Fix - This expands wrong! 1+2 * 1+2 = 5, not 9!
    printf("Macro SQUARE(1+2): %d\n", SQUARE(1+2));

    printf("Safe SQUARE(1+2): %d\n", SAFE_SQUARE(1+2));

    // Side effect bug
    int a = 5, b = 10;
    int c = MAX(a++, b++);  // TODO: This evaluates a++ or b++ TWICE!
    printf("Side effect: a=%d, b=%d, c=%d\n", a, b, c);

    return 0;
}
