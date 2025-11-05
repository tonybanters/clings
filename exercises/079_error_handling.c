// Exercise 079: Error Handling with errno
//
// C uses errno (from errno.h) to report errors!
//
// Pattern:
//   1. Call function
//   2. Check return value
//   3. If error, check errno
//   4. Use strerror(errno) or perror() to print error
//
// EXPECTED: Error opening nonexistent.txt: No such file or directory
// EXPECTED: Successfully opened existing.txt
// EXPECTED: Division by zero!
// HINT: Check return values, use perror() or strerror(errno)

#include <stdio.h>
#include <errno.h>
#include <string.h>

int safe_divide(int a, int b, int *result) {
    if (b == 0) {
        errno = EDOM;  // Domain error
        return -1;
    }
    *result = a / b;
    return 0;
}

int main(void) {
    // Try to open non-existent file
    FILE *file = fopen("nonexistent.txt", "r");
    // TODO: Check if file is NULL, then print error!
    // Hint: if (file == NULL) perror("Error opening nonexistent.txt");

    // Create a file we can open
    file = fopen("existing.txt", "w");
    // TODO: Check if file opened successfully before closing!
    fclose(file);

    file = fopen("existing.txt", "r");
    if (file != NULL) {
        printf("Successfully opened existing.txt\n");
        fclose(file);
    }

    // Safe division
    int result;
    // TODO: Fix - should check return value == -1!
    if (safe_divide(10, 0, &result) == 0) {
        printf("Result: %d\n", result);
    } else {
        printf("Division by zero!\n");
    }

    return 0;
}
