// Exercise 065: Fibonacci with Memoization
//
// Naive recursive Fibonacci is SLOW (exponential time).
// Memoization caches results to make it FAST (linear time)!
//
// This shows an important optimization technique.
//
// EXPECTED: Fibonacci(10) = 55
// EXPECTED: Fibonacci(20) = 6765
// EXPECTED: Fibonacci(30) = 832040
// HINT: Store results in array, check cache before computing

#include <stdio.h>
#include <string.h>

#define MAX_N 100

int memo[MAX_N];

int fib_memo(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Check if already computed
    // TODO: Fix this!= -1 (already computed)!
    if (memo[n] == -1) {
        return memo[n];
    }

    // Compute and store
    // TODO: Fix this!
    memo[n] = fib_memo(n - 1);

    return memo[n];
}

int main(void) {
    // Initialize memo array to -1 (not computed)
    memset(memo, -1, sizeof(memo));

    printf("Fibonacci(10) = %d\n", fib_memo(10));

    // TODO: Add memset here! Reset memo array for accurate demonstration
    printf("Fibonacci(20) = %d\n", fib_memo(20));

    memset(memo, -1, sizeof(memo));
    printf("Fibonacci(30) = %d\n", fib_memo(30));

    return 0;
}
