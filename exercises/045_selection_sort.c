// Exercise 045: Selection Sort Algorithm
//
// Selection sort finds the minimum element and moves it to the front.
//
// Algorithm:
//   1. Find minimum element in unsorted part
//   2. Swap with first element of unsorted part
//   3. Move boundary of sorted part one position right
//   4. Repeat until array is sorted
//
// Time complexity: O(n²) always
// Space complexity: O(1)
//
// Characteristics:
//   - Makes minimum number of swaps
//   - Not stable (relative order may change)
//   - In-place sorting
//
// Fix THREE selection sort bugs!
//
// EXPECTED: Original: 64 25 12 22 11
// EXPECTED: Sorted:   11 12 22 25 64
// EXPECTED: Total swaps: 4
// HINT: Fix minimum finding logic, swap operation, and loop bounds

#include <stdio.h>

void selection_sort(int arr[], int size) {
    int swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        // Find minimum element in unsorted part
        // TODO: Fix this!
        int min_idx = 0;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap minimum with first element of unsorted part
        if (min_idx != i) {
            int temp = arr[i];
            // TODO: Fix this!
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swaps++;
        }
    }

    printf("Total swaps: %d\n", swaps);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    print_array(arr, size);

    selection_sort(arr, size);

    printf("Sorted:   ");
    // TODO: Fix this!
    print_array(arr, size);

    return 0;
}
