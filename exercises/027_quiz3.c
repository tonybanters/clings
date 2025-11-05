// Exercise 027: Quiz 3 - Pointers & Strings
//
// This quiz combines:
//   - Pointers and dereferencing
//   - String manipulation
//   - Arrays and pointer arithmetic
//   - Memory concepts
//
// Create functions to manipulate strings using pointers!
//
// EXPECTED: Original: Hello
// EXPECTED: Uppercase: HELLO
// EXPECTED: Reversed: olleH
// EXPECTED: Length: 5
// HINT: Use pointers, understand string traversal, implement algorithms

#include <stdio.h>

// Convert string to uppercase (in place)
void to_uppercase(char *str) {
    // TODO: Implement this function!
    // Hint: 'a' to 'z' is 97-122, 'A' to 'Z' is 65-90
    // Subtract 32 from lowercase to get uppercase
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            // TODO: Convert to uppercase!
        }
        str++;
    }
}

// Reverse string (in place)
void reverse_string(char *str) {
    // TODO: Implement this function!
    // Hint: Use two pointers, one at start and one at end
    // Swap and move toward middle
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // TODO: Add swap logic!
}

// Calculate string length (implement strlen)
int string_length(const char *str) {
    int len = 0;
    // TODO: Implement this!
    return len;
}

int main(void) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "Hello";

    printf("Original: %s\n", str1);

    to_uppercase(str1);
    printf("Uppercase: %s\n", str1);

    reverse_string(str2);
    printf("Reversed: %s\n", str2);

    int len = string_length(str3);
    printf("Length: %d\n", len);

    return 0;
}
