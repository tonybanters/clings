// Exercise 035: void Pointers (Generic Pointers)
//
// void* is a generic pointer type that can point to anything.
//
// Rules:
//   - Can't dereference void* directly
//   - Must cast to specific type before use
//   - Useful for generic functions (like qsort, memcpy)
//   - No pointer arithmetic on void*
//
// Example:
//   void *ptr = &some_int;
//   int value = *(int *)ptr;  // cast then dereference
//
// Fix THREE void pointer bugs!
//
// EXPECTED: Integer: 42
// EXPECTED: Float: 3.14
// EXPECTED: String: Hello
// EXPECTED: Swapped: 20, 10
// HINT: Cast void* before dereferencing, understand generic programming

#include <stdio.h>
#include <string.h>

void print_value(void *ptr, char type) {
    if (type == 'i') {
        // TODO: Fix - must cast void* to int* before dereferencing!
        printf("Integer: %d\n", *ptr);
    } else if (type == 'f') {
        printf("Float: %.2f\n", *(float *)ptr);
    } else if (type == 's') {
        printf("String: %s\n", (char *)ptr);
    }
}

// Generic swap function using void pointers
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    // TODO: Fix - should copy temp to b, not a to b again!
    memcpy(b, a, size);
}

int main(void) {
    int i = 42;
    float f = 3.14;
    char *s = "Hello";

    print_value(&i, 'i');
    print_value(&f, 'f');
    print_value(s, 's');

    // Test generic swap
    int x = 10, y = 20;
    swap(&x, &y, sizeof(int));
    printf("Swapped: %d, %d\n", x, y);

    // Void pointer arithmetic (NOT ALLOWED!)
    void *ptr = &i;
    // TODO: Fix - can't do arithmetic on void*! Cast to char* or int* first
    ptr = ptr + 1;

    return 0;
}
