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
// Other allocation functions:
//   calloc(count, size) - allocates and zeros memory
//   realloc(ptr, size)  - resizes allocated memory
//
// Fix THREE memory allocation bugs!
//
// EXPECTED: Array: 1 2 3 4 5
// EXPECTED: Doubled: 2 4 6 8 10
// EXPECTED: String: Hello
// HINT: Fix allocation sizes and don't forget null terminators for strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Allocate array of 5 integers
    int *numbers = malloc(3 * sizeof(int));  // TODO: Fix size - need 5 ints!

    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill the array
    for (int i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }

    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Double each value
    printf("Doubled: ");
    for (int i = 0; i < 5; i++) {
        numbers[i] = numbers[i] * 2;  // TODO: Fix - should multiply by 2, not add!
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Allocate string (don't forget null terminator!)
    char *str = malloc(5);  // TODO: Fix - "Hello" needs 6 bytes (5 chars + '\0')!
    if (str == NULL) {
        free(numbers);
        return 1;
    }

    strcpy(str, "Hello");
    printf("String: %s\n", str);

    free(numbers);
    free(str);
    return 0;
}
