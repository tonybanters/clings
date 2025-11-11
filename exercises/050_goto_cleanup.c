// Exercise 050: goto for Error Handling Cleanup
//
// goto is controversial, but has ONE good use: cleanup on error.
//
// Pattern:
//   int func() {
//       char *buf = NULL;
//       FILE *f = NULL;
//
//       buf = malloc(size);
//       if (!buf) goto cleanup;
//
//       f = fopen(file, "r");
//       if (!f) goto cleanup;
//
//       // ... use resources ...
//
//   cleanup:
//       if (f) fclose(f);
//       if (buf) free(buf);
//       return result;
//   }
//
// Benefits:
//   - Single cleanup point
//   - No resource leaks
//   - Linear code flow
//   - Used in Linux kernel
//
// Fix THREE goto cleanup bugs!
//
// EXPECTED: Starting process...
// EXPECTED: Allocated buffer
// EXPECTED: Created temp file
// EXPECTED: Processing complete
// EXPECTED: Cleaning up...
// HINT: Add proper cleanup, fix goto logic, check all resources

#include <stdio.h>
#include <stdlib.h>

int process_with_cleanup(void) {
    int result = -1;
    char *buffer = NULL;
    FILE *temp_file = NULL;
    int *data = NULL;

    printf("Starting process...\n");

    // Allocate buffer
    buffer = malloc(1024);
    if (buffer == NULL) {
        printf("Failed to allocate buffer\n");
        // TODO: Add goto cleanup instead of direct return!
        return -1;
    }
    printf("Allocated buffer\n");

    // Allocate data
    data = malloc(100 * sizeof(int));
    if (data == NULL) {
        printf("Failed to allocate data\n");
        goto cleanup;
    }

    // Create temp file
    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Failed to create file\n");
        goto cleanup;
    }
    printf("Created temp file\n");

    // Process (simulate success)
    fprintf(temp_file, "Processing data...\n");
    printf("Processing complete\n");
    result = 0;  // Success

cleanup:
    printf("Cleaning up...\n");

    // TODO: Fix this!
    if (temp_file) {
        fclose(temp_file);
    }
    if (buffer) {
        free(buffer);
    }
    // TODO: Add cleanup for data here!

    return result;
}

int main(void) {
    int result = process_with_cleanup();

    if (result == 0) {
        printf("Success!\n");
    } else {
        printf("Failed with code: %d\n", result);
    }

    return 0;
}
