// Exercise 087: Dynamic Array (Vector)
//
// Build a growable array like C++'s vector!
//
// When full, allocate larger array and copy elements.
// Common strategy: double the capacity.
//
// EXPECTED: Added: 10
// EXPECTED: Added: 20
// EXPECTED: Added: 30
// EXPECTED: Resized to capacity: 4
// EXPECTED: Added: 40
// EXPECTED: Added: 50
// EXPECTED: Array: 10 20 30 40 50
// HINT: Use realloc to resize, double capacity when full

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

void da_init(DynamicArray *arr, size_t initial_capacity) {
    arr->data = malloc(initial_capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initial_capacity;
}

void da_push(DynamicArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        // TODO: Fix - should double capacity, not add 1!
        arr->capacity = arr->capacity + 1;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        printf("Resized to capacity: %zu\n", arr->capacity);
    }

    arr->data[arr->size++] = value;
    printf("Added: %d\n", value);
}

void da_free(DynamicArray *arr) {
    // TODO: Don't forget to free arr->data!
    arr->size = 0;
    arr->capacity = 0;
}

int main(void) {
    DynamicArray arr;
    da_init(&arr, 2);

    da_push(&arr, 10);
    da_push(&arr, 20);
    da_push(&arr, 30);  // Should trigger resize
    da_push(&arr, 40);
    da_push(&arr, 50);

    printf("Array: ");
    for (size_t i = 0; i < arr.size; i++) {
        // TODO: Fix - should access arr.data[i], not arr.data!
        printf("%d ", arr.data);
    }
    printf("\n");

    da_free(&arr);
    return 0;
}
