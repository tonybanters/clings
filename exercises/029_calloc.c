// Exercise 029: calloc - Zeroed Allocation
//
// calloc() allocates memory AND initializes it to zero.
//
// Differences from malloc():
//   malloc(size)          - allocates size bytes (uninitialized)
//   calloc(count, size)   - allocates count * size bytes (zeroed)
//
// Example:
//   int *arr1 = malloc(5 * sizeof(int));     // uninitialized
//   int *arr2 = calloc(5, sizeof(int));      // all zeros
//
// calloc is useful when:
//   - You need zeroed memory
//   - Working with arrays of structs
//   - Avoiding uninitialized value bugs
//
// Fix THREE calloc-related bugs!
//
// EXPECTED: Malloc array (uninitialized): may have garbage values
// EXPECTED: Calloc array (zeroed): 0 0 0 0 0
// EXPECTED: Struct array: Alice(0), Bob(0), Charlie(0)
// HINT: Use calloc correctly, remember it takes count and size separately

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main(void) {
    // Malloc: uninitialized memory
    int *arr1 = malloc(5 * sizeof(int));
    if (arr1 == NULL) {
        return 1;
    }

    printf("Malloc array (uninitialized): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);  // Could be anything!
    }
    printf("may have garbage values\n");

    // Calloc: zeroed memory
    // TODO: Fix - calloc takes (count, size), not (total_bytes)!
    int *arr2 = calloc(5 * sizeof(int));
    if (arr2 == NULL) {
        free(arr1);
        return 1;
    }

    printf("Calloc array (zeroed): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);  // Always 0
    }
    printf("\n");

    // Using calloc for structs
    struct Person *people = calloc(3, sizeof(struct Person));
    if (people == NULL) {
        free(arr1);
        free(arr2);
        return 1;
    }

    // Set names (ages are already 0 from calloc)
    strcpy(people[0].name, "Alice");
    strcpy(people[1].name, "Bob");
    strcpy(people[2].name, "Charlie");

    printf("Struct array: ");
    for (int i = 0; i < 3; i++) {
        printf("%s(%d)", people[i].name, people[i].age);
        if (i < 2) printf(", ");
    }
    printf("\n");

    // TODO: Fix - memory leak! Need to free people!
    free(arr1);
    free(arr2);

    return 0;
}
