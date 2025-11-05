// Exercise 082: String Tokenization
//
// Split a string by delimiter using strtok()!
//
// Important: strtok() modifies the string!
// First call: strtok(str, delim)
// Subsequent calls: strtok(NULL, delim)
//
// EXPECTED: Tokens:
// EXPECTED:   apple
// EXPECTED:   banana
// EXPECTED:   cherry
// EXPECTED:   date
// HINT: Use strtok(NULL, delim) for subsequent calls

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "apple,banana,cherry,date";
    const char *delim = ",";

    printf("Tokens:\n");

    // TODO: Fix - first call should use str, not NULL!
    char *token = strtok(NULL, delim);

    while (token != NULL) {
        printf("  %s\n", token);
        // TODO: Fix - subsequent calls should use NULL, not str!
        token = strtok(str, delim);
    }

    return 0;
}
