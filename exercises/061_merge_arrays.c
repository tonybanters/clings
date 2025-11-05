// Exercise 061: Merging Two Sorted Arrays
//
// Given two sorted arrays, merge them into one sorted array!
// This is a key part of merge sort.
//
// Algorithm:
//   - Use two pointers, one for each array
//   - Compare elements and take the smaller one
//   - Advance that pointer
//
// EXPECTED: Array 1: 1 3 5 7
// EXPECTED: Array 2: 2 4 6 8
// EXPECTED: Merged: 1 2 3 4 5 6 7 8
// HINT: Compare elements, handle remaining elements

#include <stdio.h>

void merge_arrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge while both arrays have elements
    while (i < size1 && j < size2) {
        // TODO: Fix comparison - should be <=, not >=!
        if (arr1[i] >= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1
    while (i < size1) {
        result[k++] = arr1[i++];
    }

    // TODO: Add loop to copy remaining elements from arr2!
}

int main(void) {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = 4, size2 = 4;
    int merged[8];

    printf("Array 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    printf("\n");

    merge_arrays(arr1, size1, arr2, size2, merged);

    printf("Merged: ");
    for (int i = 0; i < size1 + size2; i++) printf("%d ", merged[i]);
    printf("\n");

    return 0;
}
