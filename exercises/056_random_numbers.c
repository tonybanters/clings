// Exercise 056: Random Numbers - Fun with rand()
//
// C provides rand() for random numbers.
//
// Important:
//   - srand(seed) initializes the random generator
//   - Use time(NULL) for different seed each run
//   - rand() returns 0 to RAND_MAX
//   - rand() % n gives 0 to n-1
//
// This is a simpler exercise - just 2 bugs!
//
// EXPECTED: Random number (0-99): [some number]
// EXPECTED: Rolling dice: [1-6] [1-6] [1-6]
// EXPECTED: Random element: [one of the array elements]
// HINT: Initialize srand(), fix modulo range

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // TODO: Initialize random seed with time(NULL)!
    // Hint: srand(time(NULL));

    // Random number 0-99
    int num = rand() % 100;
    printf("Random number (0-99): %d\n", num);

    // Roll dice three times (1-6)
    printf("Rolling dice: ");
    for (int i = 0; i < 3; i++) {
        // TODO: Fix - should be rand() % 6 + 1 for 1-6!
        int roll = rand() % 6;
        printf("%d ", roll);
    }
    printf("\n");

    // Pick random element from array
    char *words[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int size = sizeof(words) / sizeof(words[0]);
    int index = rand() % size;
    printf("Random element: %s\n", words[index]);

    return 0;
}
