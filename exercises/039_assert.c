// Exercise 039: Assertions and Debugging
//
// assert() checks conditions at runtime (debug mode).
//
// Usage:
//   #include <assert.h>
//   assert(condition);  // aborts if condition is false
//
// Behavior:
//   - In debug: checks condition, aborts if false
//   - In release (NDEBUG defined): assert() is removed
//
// Use assertions for:
//   - Preconditions (function inputs)
//   - Postconditions (function outputs)
//   - Invariants (things that should always be true)
//
// Don't use for:
//   - User input validation
//   - Error handling in production
//   - Side effects (assert removed in release!)
//
// Fix THREE assertion bugs!
//
// EXPECTED: Computing factorial of 5
// EXPECTED: Result: 120
// EXPECTED: Array operations completed
// HINT: Add assertions for preconditions, fix logic errors

#include <stdio.h>
#include <assert.h>

int factorial(int n) {
    // TODO: Add assertion - n should be non-negative!

    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int array_sum(int *arr, int size) {
    // TODO: Add assertion - arr should not be NULL!
    // TODO: Add assertion - size should be positive!

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void divide(int a, int b) {
    // TODO: Fix - add assertion that b != 0!
    int result = a / b;
    printf("Result: %d\n", result);
}

int main(void) {
    printf("Computing factorial of 5\n");
    int result = factorial(5);
    printf("Result: %d\n", result);

    int numbers[] = {1, 2, 3, 4, 5};
    int sum = array_sum(numbers, 5);
    assert(sum == 15);  // Postcondition check

    printf("Array operations completed\n");

    return 0;
}
