// Exercise 085: Environment Variables
//
// Access environment variables like PATH, HOME, USER!
//
// Use getenv(name) to get environment variable value.
// Returns NULL if not found.
//
// EXPECTED: PATH exists
// EXPECTED: HOME exists
// EXPECTED: NONEXISTENT_VAR not found
// HINT: Check if getenv() returns NULL

#include <stdio.h>
#include <stdlib.h>

void check_env(const char *name) {
    char *value = getenv(name);
    // TODO: Fix condition - should check if value != NULL!
    if (value == NULL) {
        printf("%s exists\n", name);
    } else {
        printf("%s not found\n", name);
    }
}

int main(void) {
    check_env("PATH");
    check_env("HOME");
    check_env("NONEXISTENT_VAR");

    return 0;
}
