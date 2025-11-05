// Exercise 033: String Literals and Pointer Arithmetic
//
// String literals are stored in read-only memory.
//
// Two ways to use strings:
//   char *str = "hello";        // pointer to read-only string literal
//   char str[] = "hello";       // mutable array copy
//
// Important:
//   - String literals have type char[] but decay to const char *
//   - Modifying string literals = undefined behavior!
//   - Arrays are mutable, pointers to literals are not
//
// Fix THREE string literal bugs!
//
// EXPECTED: Pointer to literal: Hello
// EXPECTED: Array copy: World
// EXPECTED: Modified array: Warld
// EXPECTED: String length: 5
// HINT: Understand mutable vs immutable strings, use arrays for modification

#include <stdio.h>
#include <string.h>

int main(void) {
    // Pointer to string literal (read-only)
    char *str1 = "Hello";
    printf("Pointer to literal: %s\n", str1);

    // Array initialized with string (mutable)
    char str2[] = "World";
    printf("Array copy: %s\n", str2);

    // TODO: Fix - can't modify string literal! Use str2 instead!
    str1[0] = 'J';  // UNDEFINED BEHAVIOR!
    printf("Modified array: %s\n", str1);

    // Array of strings (array of pointers)
    char *words[] = {"One", "Two", "Three"};

    // TODO: Fix - wrong type! Should be char*, not char!
    for (char i = 0; i < 3; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // String length without strlen
    char *text = "Hello";
    int len = 0;
    // TODO: Fix - need to dereference text[len], not just check len!
    while (len != '\0') {
        len++;
    }
    printf("String length: %d\n", len);

    return 0;
}
