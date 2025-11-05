// Exercise 052: Array Reversal - Simple Practice
//
// Reversing an array is a common operation.
// Use two pointers: one at start, one at end.
// Swap and move toward the middle!
//
// This is easier than it looks - just 2 bugs to fix.
//
// EXPECTED: Original: 1 2 3 4 5
// EXPECTED: Reversed: 5 4 3 2 1
// HINT: Fix loop condition and swap logic

#include <stdio.h>

void reverse_array(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    // TODO: Fix loop condition - should be left < right!
    while (left > right) {
        // Swap elements
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original: ");
    print_array(numbers, size);

    reverse_array(numbers, size);

    // TODO: Fix label - should say "Reversed:"!
    printf("Original: ");
    print_array(numbers, size);

    return 0;
}
