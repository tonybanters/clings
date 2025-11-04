// Exercise 011: Pointer Arithmetic
//
// Pointers can be incremented and decremented to move through memory.
// When you add 1 to a pointer, it moves by the size of its type.
//
// For an int pointer:
//   ptr + 1  // moves forward by sizeof(int) bytes
//
// This is very useful for iterating through arrays!
//
// EXPECTED: 10 20 30
// HINT: Start ptr at the beginning of the array (&numbers[0])

#include <stdio.h>

int main(void) {
    int numbers[] = {10, 20, 30};
    int *ptr = &numbers[1];  // TODO: Fix - start at the beginning!

    for (int i = 0; i < 3; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
