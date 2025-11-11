// Exercise 031: sizeof Operator
//
// sizeof returns the size in bytes of a type or variable.
//
// Usage:
//   sizeof(type)      - size of a type
//   sizeof(variable)  - size of a variable
//   sizeof expression - size of an expression's result
//
// Important:
//   - sizeof is a compile-time operator (not a function!)
//   - For arrays: sizeof(arr) = total bytes, not element count!
//   - For pointers: sizeof(ptr) = pointer size (usually 8 on 64-bit)
//   - Can differ between platforms (int might be 4 or 8 bytes)
//
// Fix THREE sizeof bugs!
//
// EXPECTED: Size of int: 4
// EXPECTED: Size of pointer: 8
// EXPECTED: Size of array: 20 (5 * 4)
// EXPECTED: Array length: 5
// EXPECTED: Size of struct: 16
// HINT: Understand sizeof with arrays vs pointers, calculate array length correctly

#include <stdio.h>

struct Point {
    int x;      // 4 bytes
    int y;      // 4 bytes
    double z;   // 8 bytes
};  // Total: 16 bytes (with padding)

void print_array_size(int *arr) {
    // TODO: Fix this!
    // This is why you should pass array length separately!
    printf("Array size in function: %zu\n", sizeof(arr));
}

int main(void) {
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of pointer: %zu\n", sizeof(int *));

    int numbers[5] = {1, 2, 3, 4, 5};
    printf("Size of array: %zu (5 * 4)\n", sizeof(numbers));

    // Calculate array length
    // TODO: Fix this!
    int length = sizeof(numbers) * sizeof(numbers[0]);
    printf("Array length: %d\n", length);

    struct Point p = {10, 20, 30.0};
    printf("Size of struct: %zu\n", sizeof(p));

    // Common mistake: sizeof with pointers
    int *ptr = numbers;
    // TODO: Fix this!
    printf("Size via pointer (WRONG WAY): %zu\n", sizeof(ptr));

    return 0;
}
