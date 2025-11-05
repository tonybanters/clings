// Exercise 054: Word Counter - Practical String Processing
//
// Count words in a string!
// A word is a sequence of non-space characters.
//
// Algorithm:
//   - Count transitions from space to non-space
//   - That's when a new word starts!
//
// EXPECTED: "Hello World" has 2 words
// EXPECTED: "The quick brown fox" has 4 words
// EXPECTED: "   spaces   everywhere   " has 3 words
// HINT: Track previous character, count space-to-letter transitions

#include <stdio.h>
#include <ctype.h>

int count_words(const char *str) {
    int count = 0;
    int in_word = 0;  // Are we currently in a word?

    while (*str != '\0') {
        if (isspace(*str)) {
            in_word = 0;  // We're in whitespace
        } else {
            // TODO: Fix - should check if we were NOT in a word before!
            if (in_word) {
                count++;  // Starting a new word
            }
            in_word = 1;
        }
        str++;
    }

    return count;
}

int main(void) {
    printf("\"Hello World\" has %d words\n",
           count_words("Hello World"));

    printf("\"The quick brown fox\" has %d words\n",
           count_words("The quick brown fox"));

    // TODO: Fix - wrong string! Should test "   spaces   everywhere   "
    printf("\"   spaces   everywhere   \" has %d words\n",
           count_words("   no   spaces   "));

    return 0;
}
