// Exercise 037: Variadic Functions (Variable Arguments)
//
// Variadic functions accept variable number of arguments.
//
// Required includes:
//   #include <stdarg.h>
//
// Macros:
//   va_list args;           // declare argument list
//   va_start(args, last);   // initialize (last = last fixed param)
//   va_arg(args, type);     // get next argument of type
//   va_end(args);           // cleanup
//
// Example: printf, scanf, sum, average, etc.
//
// Important:
//   - Need at least one fixed parameter
//   - Must know types (no type checking!)
//   - Must know when to stop
//
// Fix THREE variadic function bugs!
//
// EXPECTED: Sum of 3 numbers: 6
// EXPECTED: Sum of 5 numbers: 15
// EXPECTED: Max of 4 numbers: 40
// HINT: Use va_start, va_arg, va_end correctly

#include <stdio.h>
#include <stdarg.h>

// Sum variable number of integers
int sum(int count, ...) {
    va_list args;
    // TODO: Fix this!
    va_start(args);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

// Find maximum of variable number of integers
int max(int count, ...) {
    va_list args;
    va_start(args, count);

    int maximum = va_arg(args, int);  // First value
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value > maximum) {
            maximum = value;
        }
    }

    // TODO: Fix this!

    return maximum;
}

// Print variable arguments with format
void print_values(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        // TODO: Fix type!
        printf("%d ", va_arg(args, char));
    }
    printf("\n");

    va_end(args);
}

int main(void) {
    printf("Sum of 3 numbers: %d\n", sum(3, 1, 2, 3));
    printf("Sum of 5 numbers: %d\n", sum(5, 1, 2, 3, 4, 5));
    printf("Max of 4 numbers: %d\n", max(4, 10, 20, 40, 30));

    return 0;
}
