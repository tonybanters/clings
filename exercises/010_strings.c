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
// This program should print "Hello", but it's broken!
//
// EXPECTED: Hello
// HINT: Strings need a null terminator '\0' at the end

#include <stdio.h>

int main(void) {
    char greeting[6] = {'H', 'e', 'l', 'l', 'o'};  // TODO: Missing something!

    printf("%s\n", greeting);
    return 0;
}
