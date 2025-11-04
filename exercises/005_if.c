// Exercise 005: If Statements
//
// The if statement lets you execute code conditionally.
//
// Syntax:
//   if (condition) {
//       // code to run if condition is true
//   }
//
// Comparison operators: == (equal), != (not equal), < (less than),
//                       > (greater than), <= (less or equal), >= (greater or equal)
//
// Fix the condition to make it print "Adult"!
//
// EXPECTED: Adult
// HINT: An adult is 18 or older

#include <stdio.h>

int main(void) {
    int age = 25;

    if (age < 18) {  // TODO: Fix this condition!
        printf("Adult\n");
    } else {
        printf("Minor\n");
    }

    return 0;
}
