// Exercise 017: Quiz 2 - Control Flow & Functions
//
// This quiz combines:
//   - Functions with return values
//   - Loops (for, while)
//   - Conditionals (if, switch)
//   - Arrays
//
// Create a program that finds the maximum value in an array!
//
// EXPECTED: Array: 5 12 8 3 15 7
// EXPECTED: Maximum value: 15
// EXPECTED: Found at index: 4
// EXPECTED: Sum of all elements: 50
// HINT: Implement max function, fix loops, check array operations

#include <stdio.h>

// TODO: Implement this function to find max value in array!
int find_max(int arr[], int size) {
    int max = 0;  // TODO: Should initialize to arr[0], not 0!

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// TODO: Implement this function to find index of value!
int find_index(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        // TODO: Add comparison logic!
    }
    return -1;  // Not found
}

int main(void) {
    int numbers[] = {5, 12, 8, 3, 15, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Print array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Find maximum
    int max = find_max(numbers, size);
    printf("Maximum value: %d\n", max);

    // Find index of maximum
    int index = find_index(numbers, size, max);
    printf("Found at index: %d\n", index);

    // Calculate sum
    int sum = 0;
    // TODO: Add loop to calculate sum!

    printf("Sum of all elements: %d\n", sum);

    return 0;
}
