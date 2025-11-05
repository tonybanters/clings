// Exercise 011: Pointer Arithmetic
//
// Pointers can be incremented and decremented to move through memory.
// When you add 1 to a pointer, it moves by the size of its type.
//
// For an int pointer:
//   ptr + 1  // moves forward by sizeof(int) bytes
//
// You can also use array notation with pointers:
//   ptr[i] is the same as *(ptr + i)
//
// Fix THREE pointer arithmetic bugs!
//
// EXPECTED: Forward: 10 20 30 40 50
// EXPECTED: Backward: 50 40 30 20 10
// EXPECTED: Middle three: 20 30 40
// HINT: Use pointer arithmetic and array indexing correctly

#include <stdio.h>

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = &numbers[1];  // TODO: Fix - start at the beginning!

    // Print forward
    printf("Forward: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Print backward from end
    printf("Backward: ");
    int *end_ptr = &numbers[5];  // TODO: Fix - this points past the array!
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(end_ptr - i));
    }
    printf("\n");

    // Print middle three elements using array notation
    printf("Middle three: ");
    int *mid_ptr = &numbers[1];
    for (int i = 0; i <= 2; i++) {  // TODO: Fix the loop condition!
        printf("%d ", mid_ptr[i]);
    }
    printf("\n");

    return 0;
}
