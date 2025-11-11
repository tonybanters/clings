// Exercise 015: Memory Leaks
//
// A memory leak occurs when you allocate memory but forget to free it.
// This wastes memory and can crash your program!
//
// Rule: Every malloc() needs a corresponding free()!
//
// Multiple allocations = multiple frees!
// Free in reverse order of allocation (good practice for nested structures)
//
// Fix THREE memory leaks in this program!
//
// EXPECTED: Created array of 5 elements
// EXPECTED: Created struct
// EXPECTED: Created string
// EXPECTED: Cleanup complete
// HINT: Every malloc needs a free, including nested allocations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int *values;
    int size;
};

int main(void) {
    // First allocation
    int *array = malloc(5 * sizeof(int));
    if (array == NULL) {
        return 1;
    }
    printf("Created array of 5 elements\n");

    // Second allocation - a struct
    struct Data *data = malloc(sizeof(struct Data));
    if (data == NULL) {
        return 1;  // TODO: Fix memory leak!
    }
    data->size = 10;
    data->values = malloc(10 * sizeof(int));  // Nested allocation
    if (data->values == NULL) {
        free(data);
        return 1;  // TODO: Fix memory leak!
    }
    printf("Created struct\n");

    // Third allocation - a string
    char *str = malloc(20);
    if (str == NULL) {
        return 1;  // TODO: Fix memory leaks!
    }
    strcpy(str, "Hello");
    printf("Created string\n");

    // TODO: Free all allocated memory!

    printf("Cleanup complete\n");
    return 0;
}
