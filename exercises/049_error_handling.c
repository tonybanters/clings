// Exercise 049: Error Handling Patterns
//
// C doesn't have exceptions. Error handling patterns:
//
// 1. Return codes:
//    - 0 or positive = success
//    - Negative = error code
//    - NULL = failure for pointers
//
// 2. errno (from errno.h):
//    - Global variable set by system calls
//    - Use perror() or strerror() to print
//
// 3. Check every fallible operation!
//    - malloc, fopen, etc.
//
// Best practices:
//   - Check return values
//   - Clean up resources on error
//   - Use goto for cleanup (yes, really!)
//   - Document error codes
//
// Fix THREE error handling bugs!
//
// EXPECTED: Attempting to allocate memory...
// EXPECTED: Memory allocated successfully
// EXPECTED: Attempting to open file...
// EXPECTED: Cannot open nonexistent.txt: No such file or directory
// EXPECTED: Cleanup completed
// HINT: Check return values, use perror, clean up resources

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int process_data(int size) {
    printf("Attempting to allocate memory...\n");

    int *data = malloc(size * sizeof(int));
    // TODO: Add NULL check! What if malloc fails?

    printf("Memory allocated successfully\n");

    // Simulate processing
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }

    free(data);
    return 0;
}

int read_config(const char *filename) {
    printf("Attempting to open file...\n");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // TODO: Fix - use perror to print error message with errno!
        printf("Cannot open %s\n", filename);
        return -1;
    }

    // Process file...
    fclose(file);
    return 0;
}

int main(void) {
    int result;

    result = process_data(100);
    if (result != 0) {
        printf("process_data failed\n");
        return 1;
    }

    result = read_config("nonexistent.txt");
    // TODO: Fix - should check if result != 0 (error), not == 0!
    if (result == 0) {
        printf("Warning: Could not read config file\n");
    }

    printf("Cleanup completed\n");
    return 0;
}
