// Exercise 020: Preprocessor - #define
//
// The preprocessor runs before compilation and handles directives
// that start with #.
//
// #define creates a macro (text replacement):
//   #define NAME value
//
// Everywhere NAME appears, it's replaced with value.
//
// Macros are often used for constants!
//
// EXPECTED: Circle area: 314
// HINT: Define PI as 3.14

#include <stdio.h>

// TODO: Define PI as 3.14

int main(void) {
    int radius = 10;
    float area = PI * radius * radius;

    printf("Circle area: %.0f\n", area);
    return 0;
}
