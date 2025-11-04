// Exercise 014: Dynamic Memory - malloc
//
// malloc() allocates memory on the heap (not the stack).
// This memory persists until you free() it.
//
// Usage:
//   ptr = malloc(size_in_bytes);
//   // use ptr
//   free(ptr);
//
// Always check if malloc returns NULL (allocation failed)!
// Always free() memory when done!
//
// EXPECTED: Array: 1 2 3 4 5
// HINT: Allocate 5 integers: malloc(5 * sizeof(int))

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *numbers = malloc(3 * sizeof(int));  // TODO: Fix size - need 5 ints!

    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill the array
    for (int i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);  // Always free allocated memory!
    return 0;
}
