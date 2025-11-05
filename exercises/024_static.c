// Exercise 024: Static Variables and Functions
//
// The static keyword has different meanings in different contexts:
//
// 1. Static local variables:
//    - Persist between function calls
//    - Initialized only once
//    - Keep their value across calls
//
// 2. Static global variables/functions:
//    - Limited to file scope (internal linkage)
//    - Not visible to other source files
//
// Fix THREE static-related bugs!
//
// EXPECTED: Call 1: Counter = 1
// EXPECTED: Call 2: Counter = 2
// EXPECTED: Call 3: Counter = 3
// EXPECTED: ID: 100
// EXPECTED: ID: 101
// EXPECTED: ID: 102
// HINT: Use static for persistent state, fix initialization, understand scope

#include <stdio.h>

// Static function - only visible in this file
static int next_id(void) {
    int id = 100;  // TODO: Make this static so it persists between calls!
    return id++;
}

void increment_counter(void) {
    int count = 0;  // TODO: Make this static so it keeps its value!
    count++;
    printf("Counter = %d\n", count);
}

int main(void) {
    printf("Call 1: ");
    increment_counter();

    printf("Call 2: ");
    increment_counter();

    printf("Call 3: ");
    increment_counter();

    // Generate some IDs
    printf("ID: %d\n", next_id());
    printf("ID: %d\n", next_id());
    // TODO: Fix - missing third call to match expected output!

    return 0;
}
