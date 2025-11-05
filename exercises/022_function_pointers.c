// Exercise 022: Function Pointers
//
// Functions have addresses too! You can store them in pointers.
//
// Declaration:
//   int (*func_ptr)(int, int);  // pointer to function taking 2 ints, returning int
//
// Usage:
//   func_ptr = &add;  // or just: func_ptr = add;
//   int result = func_ptr(5, 3);  // or: (*func_ptr)(5, 3);
//
// Function pointers are useful for:
//   - Callback functions
//   - Plugin systems
//   - Strategy pattern
//   - Jump tables
//
// Fix THREE function pointer bugs!
//
// EXPECTED: Add: 5 + 3 = 8
// EXPECTED: Subtract: 5 - 3 = 2
// EXPECTED: Multiply: 5 * 3 = 15
// EXPECTED: Using function pointer: 8
// HINT: Match function signatures, assign correctly, call properly

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// TODO: Fix the return type - should match the functions above!
void apply_operation(int (*op)(int, int), int x, int y) {
    int result = op(x, y);
    printf("Using function pointer: %d\n", result);
}

int main(void) {
    int x = 5, y = 3;

    printf("Add: %d + %d = %d\n", x, y, add(x, y));
    printf("Subtract: %d - %d = %d\n", x, y, subtract(x, y));
    printf("Multiply: %d * %d = %d\n", x, y, multiply(x, y));

    // TODO: Fix - missing & operator to get function address!
    int (*func_ptr)(int, int) = add;
    apply_operation(func_ptr, x, y);

    // Array of function pointers
    int (*operations[3])(int, int) = {add, subtract, multiply};

    // TODO: Fix - wrong index and wrong call syntax!
    int result = operations(x, y);

    return 0;
}
