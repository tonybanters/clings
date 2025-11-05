// Exercise 020: Preprocessor Directives
//
// The preprocessor runs before compilation and handles directives
// that start with #.
//
// Common directives:
//   #define NAME value    - defines a macro (text replacement)
//   #ifdef NAME          - conditional compilation
//   #ifndef NAME         - if not defined
//   #endif               - ends conditional block
//
// Function-like macros:
//   #define MAX(a,b) ((a) > (b) ? (a) : (b))
//
// Be careful with macros! Always use parentheses!
//
// Fix THREE preprocessor bugs!
//
// EXPECTED: Circle area: 314
// EXPECTED: Max of 5 and 10: 10
// EXPECTED: Debug mode: ON
// EXPECTED: Version: 1.0
// HINT: Define macros, fix macro syntax, and use conditional compilation

#include <stdio.h>

// TODO: Define PI as 3.14

// TODO: Define MAX macro that returns the larger of two values
// Hint: #define MAX(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 1
#define VERSION "1.0"

int main(void) {
    // Test PI
    int radius = 10;
    float area = PI * radius * radius;
    printf("Circle area: %.0f\n", area);

    // Test MAX macro
    int a = 5, b = 10;
    printf("Max of %d and %d: %d\n", a, b, MAX(a, b));

    // Conditional compilation
    #ifdef DEBUG
        printf("Debug mode: ON\n");
    #endif

    // TODO: This should be inside #ifdef VERSION, not #ifndef!
    #ifndef VERSION
        printf("Version: %s\n", VERSION);
    #endif

    return 0;
}
