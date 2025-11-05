// Exercise 046: Insertion Sort Algorithm
//
// Insertion sort builds sorted array one element at a time.
//
// Algorithm:
//   1. Start with second element
//   2. Compare with elements in sorted part (to the left)
//   3. Shift elements right to make space
//   4. Insert element in correct position
//   5. Repeat for all elements
//
// Time complexity:
//   - Best: O(n) - already sorted
//   - Average: O(n²)
//   - Worst: O(n²) - reverse sorted
//
// Space complexity: O(1)
//
// Good for: small arrays, nearly sorted data, online sorting
//
// Fix THREE insertion sort bugs!
//
// EXPECTED: Original: 12 11 13 5 6
// EXPECTED: Sorted:   5 6 11 12 13
// EXPECTED: Comparisons: 9
// HINT: Fix loop direction, insertion logic, and boundary checks

#include <stdio.h>

void insertion_sort(int arr[], int size) {
    int comparisons = 0;

    // Start from second element
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position right
        // TODO: Fix - should be arr[j] > key, not arr[j] < key!
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }

        // Insert key at correct position
        // TODO: Fix - should be j + 1, not j!
        arr[j] = key;
    }

    printf("Comparisons: %d\n", comparisons);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    print_array(arr, size);

    // TODO: Fix - missing function call to insertion_sort!

    printf("Sorted:   ");
    print_array(arr, size);

    return 0;
}
