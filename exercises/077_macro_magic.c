// Exercise 077: Advanced Macros
//
// Macros are preprocessor text replacements!
//
// Tips:
//   - Use do { ... } while(0) for multi-statement macros
//   - # stringifies, ## concatenates tokens
//   - Use parentheses around arguments!
//
// EXPECTED: Max of 5 and 3: 5
// EXPECTED: Square of 4: 16
// EXPECTED: DEBUG: x = 10
// EXPECTED: Added two numbers: result = 15
// HINT: Wrap macro bodies in do-while, use # for stringification

#include <stdio.h>

// TODO: Fix this!
#define MAX(a, b) a > b ? a : b

// TODO: Fix this!
#define SQUARE(x) x * x

// Stringify macro (turns argument into string)
#define STRINGIFY(x) #x

// Debug macro (prints variable name and value)
// TODO: Fix this!
#define DEBUG(x) printf("DEBUG: %s = %d\n", "var", x)

// Multi-statement macro
// TODO: Wrap in do { ... } while(0) for safety!
#define LOG_AND_ADD(a, b, result) \
    printf("Added two numbers: "); \
    result = a + b; \
    printf("result = %d\n", result);

int main(void) {
    printf("Max of 5 and 3: %d\n", MAX(5, 3));
    printf("Square of 4: %d\n", SQUARE(4));

    int x = 10;
    DEBUG(x);

    int sum;
    LOG_AND_ADD(5, 10, sum);

    return 0;
}
