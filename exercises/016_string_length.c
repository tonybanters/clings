// Exercise 016: String Length
//
// The strlen() function from <string.h> returns the length of a string
// (not counting the null terminator).
//
// Usage:
//   size_t len = strlen(str);
//
// Write a function that counts characters manually!
//
// EXPECTED: Length: 5
// HINT: Loop until you find '\0', counting each character

#include <stdio.h>

int my_strlen(const char *str) {
    int count = 0;

    // TODO: Count characters until '\0'
    // Hint: while (str[count] != '\0') { ... }

    return count;
}

int main(void) {
    char word[] = "Hello";
    int len = my_strlen(word);

    printf("Length: %d\n", len);
    return 0;
}
