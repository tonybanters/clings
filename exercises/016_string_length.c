// Exercise 016: String Length
//
// The strlen() function from <string.h> returns the length of a string
// (not counting the null terminator).
//
// Usage:
//   size_t len = strlen(str);
//
// Let's implement our own string functions!
//
// Fix THREE string function bugs!
//
// EXPECTED: Length of 'Hello': 5
// EXPECTED: Length of 'World': 5
// EXPECTED: Comparing 'Hello' and 'Hello': Equal
// EXPECTED: Comparing 'Hello' and 'World': Not equal
// HINT: Loop until '\0', compare character by character, handle edge cases

#include <stdio.h>

int my_strlen(const char *str) {
    int count = 0;

    // TODO: Count characters until '\0'
    // Hint: while (str[count] != '\0') { count++; }

    return count;
}

// Returns 1 if strings are equal, 0 otherwise
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  // Not equal
        }
        i++;
    }

    // TODO: Check if both strings ended at the same position!
    // If one is longer, they're not equal!
    return 1;  // Equal
}

int main(void) {
    char word1[] = "Hello";
    char word2[] = "World";
    char word3[] = "Hello";

    int len1 = my_strlen(word1);
    int len2 = my_strlen(word2);

    printf("Length of 'Hello': %d\n", len1);
    printf("Length of 'World': %d\n", len2);

    // TODO: Fix the function call - wrong function name!
    if (strcmp(word1, word3)) {
        printf("Comparing 'Hello' and 'Hello': Equal\n");
    } else {
        printf("Comparing 'Hello' and 'Hello': Not equal\n");
    }

    if (my_strcmp(word1, word2)) {
        printf("Comparing 'Hello' and 'World': Equal\n");
    } else {
        printf("Comparing 'Hello' and 'World': Not equal\n");
    }

    return 0;
}
