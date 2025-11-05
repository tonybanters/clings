// Exercise 058: Finding Min and Max - Practice
//
// Simple practice with array traversal.
// Find both minimum and maximum in one pass!
//
// EXPECTED: Array: 45 23 67 12 89 34
// EXPECTED: Minimum: 12
// EXPECTED: Maximum: 89
// EXPECTED: Range: 77
// HINT: Initialize min/max correctly, fix calculations

#include <stdio.h>

void find_min_max(int arr[], int size, int *min, int *max) {
    if (size == 0) {
        return;
    }

    // TODO: Initialize to first element, not 0!
    *min = 0;
    *max = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main(void) {
    int numbers[] = {45, 23, 67, 12, 89, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int min, max;
    find_min_max(numbers, size, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    // TODO: Fix - range is max - min, not max + min!
    int range = max + min;
    printf("Range: %d\n", range);

    return 0;
}
