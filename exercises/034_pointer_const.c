// Exercise 034: Pointer and const - Deep Dive
//
// Understanding const with pointers is crucial!
//
// Four combinations:
//   int *ptr;                  // mutable pointer to mutable int
//   const int *ptr;            // mutable pointer to const int
//   int *const ptr;            // const pointer to mutable int
//   const int *const ptr;      // const pointer to const int
//
// Read right-to-left:
//   "ptr is a const pointer to a const int"
//
// Fix THREE const pointer bugs!
//
// EXPECTED: Value: 42
// EXPECTED: Via ptr1: 42
// EXPECTED: Changed value: 100
// EXPECTED: Via ptr2: 100
// EXPECTED: Array: 5 5 5 5 5
// HINT: Understand what const protects, fix violations

#include <stdio.h>

void fill_array(const int *arr, int size, int value) {
    // TODO: Fix this!
    // Change parameter to: int *arr
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

int main(void) {
    int value = 42;

    // Mutable pointer to const int (can't change value via pointer)
    const int *ptr1 = &value;
    printf("Value: %d\n", value);
    printf("Via ptr1: %d\n", *ptr1);

    // But can change value directly!
    value = 100;
    printf("Changed value: %d\n", value);

    // TODO: Fix this!
    *ptr1 = 200;

    // Const pointer to mutable int (can't change where it points)
    int x = 10, y = 20;
    int *const ptr2 = &x;
    *ptr2 = 15;  // OK - can modify value

    // TODO: Fix this!
    ptr2 = &y;

    printf("Via ptr2: %d\n", *ptr2);

    // Using function with const
    int numbers[5];
    fill_array(numbers, 5, 5);

    printf("Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
