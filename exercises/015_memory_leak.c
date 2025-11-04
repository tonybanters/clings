// Exercise 015: Memory Leaks
//
// A memory leak occurs when you allocate memory but forget to free it.
// This wastes memory and can crash your program!
//
// Rule: Every malloc() needs a corresponding free()!
//
// Fix the memory leak in this program!
//
// EXPECTED: Created array
// HINT: Add free() before returning

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *data = malloc(100 * sizeof(int));

    if (data == NULL) {
        return 1;
    }

    printf("Created array\n");

    // TODO: Free the allocated memory before returning!

    return 0;
}
