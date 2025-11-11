// Exercise 075: Bit Manipulation Tricks
//
// Learn some clever bit tricks!
//
// Common tricks:
//   Check if power of 2: (n & (n-1)) == 0
//   Count set bits: loop and check n & 1, then n >>= 1
//   Swap without temp: a ^= b; b ^= a; a ^= b;
//
// EXPECTED: 8 is power of 2: Yes
// EXPECTED: 10 is power of 2: No
// EXPECTED: Bits set in 23: 4
// EXPECTED: Swapped: a=20, b=10
// HINT: Use bitwise operations, not arithmetic

#include <stdio.h>

int is_power_of_two(int n) {
    // TODO: Fix this!
    return n > 0;
}

int count_set_bits(int n) {
    int count = 0;
    while (n) {
        // TODO: Fix this!
        count += (n % 2);
        n >>= 1;
    }
    return count;
}

int main(void) {
    printf("8 is power of 2: %s\n", is_power_of_two(8) ? "Yes" : "No");
    printf("10 is power of 2: %s\n", is_power_of_two(10) ? "Yes" : "No");

    printf("Bits set in 23: %d\n", count_set_bits(23));  // 23 = 10111

    int a = 10, b = 20;
    // TODO: Implement XOR swap (no temp variable)!
    // Hint: a ^= b; b ^= a; a ^= b;
    int temp = a;
    a = b;
    b = temp;

    printf("Swapped: a=%d, b=%d\n", a, b);

    return 0;
}
