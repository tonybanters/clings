// Exercise 060: Quiz 6 - String and Array Practice
//
// Time for another quiz!
// This one focuses on practical string and array manipulation.
//
// Implement three useful functions from scratch!
//
// EXPECTED: Original: hello world
// EXPECTED: Capitalized: Hello World
// EXPECTED: Array sum: 150
// EXPECTED: Array average: 30.0
// EXPECTED: Contains 35: Yes
// EXPECTED: Contains 99: No
// HINT: Implement functions completely, handle edge cases

#include <stdio.h>
#include <ctype.h>

// Capitalize first letter of each word
void capitalize_words(char *str) {
    int new_word = 1;  // Start of string is new word

    // TODO: Implement this function!
    // Hint: if new_word and isalpha(), use toupper()
    //       if space, set new_word = 1
    //       otherwise set new_word = 0
}

// Calculate sum of array
int array_sum(int arr[], int size) {
    // TODO: Implement this function!
    return 0;
}

// Calculate average of array
float array_average(int arr[], int size) {
    if (size == 0) {
        return 0.0;
    }
    // TODO: Implement using array_sum()!
    return 0.0;
}

// Check if array contains value
int array_contains(int arr[], int size, int value) {
    // TODO: Implement this function!
    return 0;
}

int main(void) {
    // Test capitalize
    char text[] = "hello world";
    printf("Original: %s\n", text);
    capitalize_words(text);
    printf("Capitalized: %s\n", text);

    // Test array functions
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array sum: %d\n", array_sum(numbers, size));
    printf("Array average: %.1f\n", array_average(numbers, size));

    printf("Contains 35: %s\n",
           array_contains(numbers, size, 35) ? "Yes" : "No");
    printf("Contains 99: %s\n",
           array_contains(numbers, size, 99) ? "Yes" : "No");

    return 0;
}
