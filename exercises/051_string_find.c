// Exercise 051: String Search - Finding Substrings
//
// Let's implement strstr() - finding a substring in a string!
//
// Algorithm:
//   1. For each position in the main string
//   2. Check if substring matches starting there
//   3. Return pointer to match or NULL
//
// This is simpler than you think!
//
// EXPECTED: Found "World" at position 6
// EXPECTED: "xyz" not found
// EXPECTED: Found "the" at position 0
// HINT: Use two nested loops, compare character by character

#include <stdio.h>
#include <string.h>

// Find first occurrence of needle in haystack
char* find_substring(char *haystack, const char *needle) {
    // Empty needle matches immediately
    if (*needle == '\0') {
        return haystack;
    }

    // TODO: Implement the search!
    // Hint: outer loop goes through haystack
    //       inner loop checks if needle matches at current position

    return NULL;  // Not found
}

int main(void) {
    char text[] = "Hello World";

    char *result = find_substring(text, "World");
    if (result != NULL) {
        printf("Found \"World\" at position %ld\n", result - text);
    }

    result = find_substring(text, "xyz");
    if (result == NULL) {
        printf("\"xyz\" not found\n");
    }

    // TODO: Fix this!
    result = find_substring("the quick brown fox", "quick");
    if (result != NULL) {
        printf("Found \"the\" at position %ld\n", result - "the quick brown fox");
    }

    return 0;
}
