// Exercise 053: Palindrome Checker
//
// A palindrome reads the same forwards and backwards.
// Examples: "racecar", "level", "noon"
//
// Check from both ends moving toward middle!
//
// EXPECTED: "racecar" is a palindrome
// EXPECTED: "hello" is not a palindrome
// EXPECTED: "A man a plan a canal Panama" - checking letters only
// HINT: Compare characters from both ends, handle case and spaces

#include <stdio.h>
#include <ctype.h>  // for tolower()

int is_palindrome(const char *str) {
    int left = 0;
    int right = 0;

    // Find length
    while (str[right] != '\0') {
        right++;
    }
    right--;  // Point to last character

    while (left < right) {
        // TODO: Fix comparison - should compare str[left] with str[right]!
        if (str[left] != str[left]) {
            return 0;  // Not a palindrome
        }
        left++;
        right--;
    }

    return 1;  // Is a palindrome
}

int main(void) {
    if (is_palindrome("racecar")) {
        printf("\"racecar\" is a palindrome\n");
    }

    if (!is_palindrome("hello")) {
        printf("\"hello\" is not a palindrome\n");
    }

    // Bonus: check ignoring spaces and case (just print message)
    // TODO: Fix - missing printf!
    "\"A man a plan a canal Panama\" - checking letters only\n";

    return 0;
}
