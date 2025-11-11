// Exercise 030: realloc - Resizing Allocations
//
// realloc() changes the size of previously allocated memory.
//
// Usage:
//   ptr = realloc(ptr, new_size);
//
// Behavior:
//   - If ptr is NULL, acts like malloc()
//   - If new_size is 0, acts like free()
//   - May move memory to new location
//   - Preserves existing data (up to smaller of old/new size)
//   - Returns NULL on failure (original ptr still valid!)
//
// Important:
//   - ALWAYS check return value
//   - Don't lose original pointer if realloc fails!
//   - Memory may move, so update all pointers
//
// Fix THREE realloc bugs!
//
// EXPECTED: Initial array: 1 2 3 4 5
// EXPECTED: Expanded array: 1 2 3 4 5 6 7 8 9 10
// EXPECTED: Shrunk array: 1 2 3
// HINT: Check for NULL, use temporary variable, understand size changes

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Start with array of 5 integers
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    // Initialize
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Initial array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Expand to 10 elements
    // TODO: Fix this!
    // Should use: int *temp = realloc(arr, ...); check temp, then arr = temp;
    arr = realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Realloc failed!\n");
        return 1;
    }

    // Fill new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }

    printf("Expanded array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Shrink to 3 elements
    int *temp = realloc(arr, 3 * sizeof(int));
    if (temp == NULL) {
        // TODO: Fix this!
        // Should keep using arr with original size
        free(arr);
        return 1;
    }
    arr = temp;

    printf("Shrunk array: ");
    // TODO: Fix this!
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
