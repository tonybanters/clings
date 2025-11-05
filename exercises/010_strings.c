// Exercise 010: Strings
//
// In C, strings are arrays of characters ending with '\0' (null terminator).
//
// String literals:
//   "hello"      // automatically null-terminated
//
// Character arrays:
//   char str[] = "hello";  // creates array with '\0' at the end
//   char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};  // manual version
//
// Strings can be accessed like arrays since they ARE arrays!
//
// Fix THREE string-related bugs!
//
// EXPECTED: Greeting: Hello
// EXPECTED: First char: H
// EXPECTED: Modified: Jello
// HINT: Strings need null terminators, use correct format specifiers, and can be modified

#include <stdio.h>

int main(void) {
    char greeting[6] = {'H', 'e', 'l', 'l', 'o'};  // TODO: Missing null terminator!

    printf("Greeting: %s\n", greeting);

    // Access first character
    char first = greeting[0];
    printf("First char: %d\n", first);  // TODO: Fix format specifier for char!

    // Modify the string
    greeting[0] = 'J';
    greeting[1] = 'a';  // TODO: Fix - should be 'e' to make "Jello"!

    printf("Modified: %s\n", greeting);
    return 0;
}
