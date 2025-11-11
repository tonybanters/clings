// Exercise 088: Generic Swap with void*
//
// Write a swap function that works with ANY type!
//
// Use void* and memcpy to swap raw bytes.
//
// EXPECTED: Before: a=5, b=10
// EXPECTED: After: a=10, b=5
// EXPECTED: Before: x=3.14, y=2.71
// EXPECTED: After: x=2.71, y=3.14
// HINT: Use memcpy with void*, need temp buffer of size bytes

#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {
    // TODO: Allocate temporary buffer of size bytes!
    // Hint: char temp[size]; or malloc

    // TODO: Implement swap using memcpy!
    // Hint: memcpy(temp, a, size);
    //       memcpy(a, b, size);
    //       memcpy(b, temp, size);
}

int main(void) {
    int a = 5, b = 10;
    printf("Before: a=%d, b=%d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After: a=%d, b=%d\n", a, b);

    float x = 3.14f, y = 2.71f;
    printf("Before: x=%.2f, y=%.2f\n", x, y);
    // TODO: Fix this!
    swap(&x, &y, sizeof(int));
    printf("After: x=%.2f, y=%.2f\n", x, y);

    return 0;
}
