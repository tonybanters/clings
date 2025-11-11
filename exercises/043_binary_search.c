// Exercise 043: Binary Search Algorithm
//
// Binary search finds an element in a SORTED array in O(log n) time.
//
// Algorithm:
//   1. Compare target with middle element
//   2. If equal, found!
//   3. If target < middle, search left half
//   4. If target > middle, search right half
//   5. Repeat until found or range is empty
//
// Requirements:
//   - Array MUST be sorted
//   - Random access (arrays, not linked lists)
//
// Time complexity: O(log n)
// Space complexity: O(1) iterative, O(log n) recursive
//
// Fix THREE binary search bugs!
//
// EXPECTED: Found 30 at index 2
// EXPECTED: Found 70 at index 6
// EXPECTED: 90 not found
// EXPECTED: Recursive: Found 50 at index 4
// HINT: Fix middle calculation, comparison logic, and recursive calls

#include <stdio.h>

// Iterative binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // TODO: Fix this!
        int mid = left + right;

        if (arr[mid] == target) {
            return mid;  // Found
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }

    return -1;  // Not found
}

// Recursive binary search
int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;  // Not found
    }

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        // TODO: Fix this!
        return binary_search_recursive(arr, left, mid - 1, target);
    } else {
        return binary_search_recursive(arr, left, mid - 1, target);
    }
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = binary_search(arr, size, 30);
    if (index != -1) {
        printf("Found 30 at index %d\n", index);
    }

    index = binary_search(arr, size, 70);
    if (index != -1) {
        printf("Found 70 at index %d\n", index);
    }

    // TODO: Fix this!
    index = binary_search(arr, size, 80);
    if (index == -1) {
        printf("90 not found\n");
    }

    // Test recursive version
    index = binary_search_recursive(arr, 0, size - 1, 50);
    if (index != -1) {
        printf("Recursive: Found 50 at index %d\n", index);
    }

    return 0;
}
