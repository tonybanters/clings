// Exercise 006: Loops
//
// Loops let you repeat code. The for loop has three parts:
//   for (initialization; condition; increment) {
//       // code to repeat
//   }
//
// This loop should count from 1 to 5, but something is wrong!
//
// EXPECTED: 1 2 3 4 5
// HINT: The loop condition should check if i is less than or equal to 5

#include <stdio.h>

int main(void) {
    for (int i = 1; i < 5; i++) {  // TODO: Fix the condition!
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
