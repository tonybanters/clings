// Exercise 044: Bubble Sort Algorithm
//
// Bubble sort repeatedly swaps adjacent elements if they're in wrong order.
//
// Algorithm:
//   1. Compare adjacent elements
//   2. Swap if out of order
//   3. Repeat for entire array
//   4. After each pass, largest element "bubbles" to the end
//   5. Repeat until no more swaps needed
//
// Time complexity:
//   - Best: O(n) with optimization
//   - Average: O(n²)
//   - Worst: O(n²)
//
// Space complexity: O(1)
//
// Fix THREE bubble sort bugs!
//
// EXPECTED: Original: 64 34 25 12 22 11 90
// EXPECTED: Sorted:   11 12 22 25 34 64 90
// EXPECTED: Passes: 6
// HINT: Fix loop bounds, swap logic, and optimization

#include <stdio.h>

void bubble_sort(int arr[], int size) {
    int passes = 0;

    // TODO: Fix - outer loop should be size-1, not size!
    for (int i = 0; i < size; i++) {
        int swapped = 0;

        // Inner loop: compare adjacent elements
        // TODO: Fix - should be size-i-1 (last i elements are sorted)!
        for (int j = 0; j < size; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        passes++;

        // Optimization: if no swaps, array is sorted
        if (!swapped) {
            break;
        }
    }

    printf("Passes: %d\n", passes);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    print_array(arr, size);

    bubble_sort(arr, size);

    // TODO: Fix - print "Sorted:" not "Original:"!
    printf("Original: ");
    print_array(arr, size);

    return 0;
}
