// Exercise 023: The const Qualifier
//
// const makes variables read-only (constant).
//
// With pointers, const can apply to different things:
//   const int *ptr;        // pointer to constant int (can't change value via ptr)
//   int *const ptr;        // constant pointer (can't change where ptr points)
//   const int *const ptr;  // both constant
//
// Read it right-to-left:
//   const int *ptr = "ptr is a pointer to a constant int"
//   int *const ptr = "ptr is a constant pointer to an int"
//
// Fix THREE const-related bugs!
//
// EXPECTED: Initial value: 42
// EXPECTED: Changed via pointer: 100
// EXPECTED: Array: 1 2 3 4 5
// EXPECTED: Sum: 15
// HINT: Understand what const protects, fix violations, use proper types

#include <stdio.h>

// This function should NOT modify the array
int sum_array(int *arr, int size) {  // TODO: Fix this!
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        arr[i] = 0;  // BUG: This shouldn't be allowed!
    }
    return sum;
}

int main(void) {
    int value = 42;
    const int *ptr = &value;  // ptr points to constant int

    printf("Initial value: %d\n", value);

    // TODO: Fix this!
    *ptr = 100;
    printf("Changed via pointer: %d\n", value);

    // Constant pointer (can modify value, but not move pointer)
    int x = 10, y = 20;
    int *const const_ptr = &x;
    *const_ptr = 15;  // OK
    // const_ptr = &y;  // This would be an error!

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int total = sum_array(numbers, 5);
    printf("Sum: %d\n", total);

    // TODO: Fix this!

    return 0;
}
