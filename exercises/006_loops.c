// Exercise 006: Loops
//
// Loops let you repeat code. C has several types of loops:
//   - for loop: for (init; condition; increment) { ... }
//   - while loop: while (condition) { ... }
//   - do-while loop: do { ... } while (condition);
//
// Fix THREE bugs to make all loops work correctly!
//
// EXPECTED: Counting up: 1 2 3 4 5
// EXPECTED: Counting down: 5 4 3 2 1
// EXPECTED: Sum: 15
// HINT: Check initialization values, loop conditions, and increment/decrement

#include <stdio.h>

int main(void) {
    // Count from 1 to 5
    printf("Counting up: ");
    for (int i = 1; i < 5; i++) {  // TODO: Fix the condition!
        printf("%d ", i);
    }
    printf("\n");

    // Count down from 5 to 1
    printf("Counting down: ");
    int j = 5;
    while (j > 0) {
        printf("%d ", j);
        j++;  // TODO: Fix this! Should decrement
    }
    printf("\n");

    // Sum numbers from 1 to 5
    printf("Sum: ");
    int sum = 0;
    int k = 0;  // TODO: Fix the starting value!
    do {
        sum += k;
        k++;
    } while (k <= 5);
    printf("%d\n", sum);

    return 0;
}
