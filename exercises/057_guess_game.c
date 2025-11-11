// Exercise 057: Number Guessing Game - Fun Mini Project!
//
// Let's build a simple game!
// Computer picks a random number, you guess it.
//
// This is a complete program to fix - easier than recent ones!
//
// EXPECTED: I'm thinking of a number between 1 and 100
// EXPECTED: [game plays with user input]
// HINT: Fix random range, comparison logic, and scanf

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    // Pick random number 1-100
    // TODO: Fix this!
    int secret = rand() % 100;
    int guess;
    int attempts = 0;

    printf("I'm thinking of a number between 1 and 100\n");
    printf("Can you guess it?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        // TODO: Fix this!
        if (guess > secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! You got it in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}
