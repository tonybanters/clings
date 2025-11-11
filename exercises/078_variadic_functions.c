// Exercise 078: Variadic Functions
//
// Functions that accept variable number of arguments!
//
// Use <stdarg.h>:
//   va_list args;
//   va_start(args, last_param);
//   va_arg(args, type);
//   va_end(args);
//
// EXPECTED: Sum of 3 numbers: 60
// EXPECTED: Sum of 5 numbers: 150
// EXPECTED: Max of 4 numbers: 90
// HINT: Use va_start, va_arg in loop, va_end

#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        // TODO: Fix this!
        total += count;
    }

    // TODO: Don't forget va_end(args)!

    return total;
}

int max(int count, ...) {
    if (count == 0) return 0;

    va_list args;
    va_start(args, count);

    // TODO: Fix this!
    int maximum = 0;

    for (int i = 0; i < count; i++) {
        int val = va_arg(args, int);
        if (val > maximum) {
            maximum = val;
        }
    }

    va_end(args);
    return maximum;
}

int main(void) {
    printf("Sum of 3 numbers: %d\n", sum(3, 10, 20, 30));
    printf("Sum of 5 numbers: %d\n", sum(5, 10, 20, 30, 40, 50));
    printf("Max of 4 numbers: %d\n", max(4, 10, 90, 30, 45));

    return 0;
}
