// Exercise 062: Remove Duplicates from Array
//
// Remove duplicate values from an array.
// Keep the first occurrence of each value.
//
// This is a practical problem you'll see in interviews!
//
// EXPECTED: Original: 1 2 2 3 4 4 5
// EXPECTED: After removing duplicates: 1 2 3 4 5
// EXPECTED: New size: 5
// HINT: Use nested loops or track seen values, shift elements

#include <stdio.h>

int remove_duplicates(int arr[], int size) {
    if (size == 0) return 0;

    int new_size = 1;  // First element is always kept

    for (int i = 1; i < size; i++) {
        int is_duplicate = 0;

        // Check if arr[i] already exists in first new_size elements
        for (int j = 0; j < new_size; j++) {
            // TODO: Fix this!
            if (arr[i] != arr[j]) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            // TODO: Fix this!
            arr[new_size] = arr[0];
            new_size++;
        }
    }

    return new_size;
}

int main(void) {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = 7;

    printf("Original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int new_size = remove_duplicates(arr, size);

    printf("After removing duplicates: ");
    // TODO: Fix this!
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("New size: %d\n", new_size);

    return 0;
}
