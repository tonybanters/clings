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
// Logical operators: && (AND), || (OR), ! (NOT)
//
// Fix THREE conditional logic bugs!
//
// EXPECTED: Status: Adult
// EXPECTED: Temperature: Cold
// EXPECTED: Access: Granted
// HINT: Check comparison operators and the logic flow carefully

#include <stdio.h>

int main(void) {
    int age = 25;

    if (age < 18) {  // TODO: Fix this condition!
        printf("Status: Adult\n");
    } else {
        printf("Status: Minor\n");
    }

    int temperature = 10;

    if (temperature > 20) {  // TODO: Fix this condition!
        printf("Temperature: Cold\n");
    } else {
        printf("Temperature: Warm\n");
    }

    int has_key = 1;
    int is_authorized = 1;

    if (has_key && is_authorized) {  // TODO: Fix the print statements!
        printf("Access: Denied\n");
    } else {
        printf("Access: Granted\n");
    }

    return 0;
}
