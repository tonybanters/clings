// Exercise 028: String Manipulation - strcpy, strncpy, strcat
//
// Common string functions from <string.h>:
//   strcpy(dest, src)      - copy string (DANGEROUS! No bounds check)
//   strncpy(dest, src, n)  - copy at most n characters (SAFER)
//   strcat(dest, src)      - append string (DANGEROUS!)
//   strncat(dest, src, n)  - append at most n characters (SAFER)
//
// Important:
//   - Destination must have enough space!
//   - strncpy may not null-terminate!
//   - Always leave room for '\0'
//
// Fix THREE string manipulation bugs!
//
// EXPECTED: Copied: Hello
// EXPECTED: Safe copy: World
// EXPECTED: Concatenated: Hello World
// EXPECTED: Name: John Doe
// HINT: Check buffer sizes, null terminators, and safe practices

#include <stdio.h>
#include <string.h>

int main(void) {
    // Simple copy
    char dest1[20];
    strcpy(dest1, "Hello");
    printf("Copied: %s\n", dest1);

    // Safe copy with strncpy
    char dest2[6];  // TODO: Fix - need 6 bytes for "World" + '\0'!
    strncpy(dest2, "World", sizeof(dest2) - 1);
    dest2[sizeof(dest2) - 1] = '\0';  // Always null-terminate after strncpy!
    printf("Safe copy: %s\n", dest2);

    // Concatenation
    char dest3[20] = "Hello";
    strcat(dest3, " World");  // TODO: Fix - space is missing!
    printf("Concatenated: %s\n", dest3);

    // Building a full name
    char first_name[] = "John";
    char last_name[] = "Doe";
    char full_name[50];

    // TODO: Fix - copy first_name first, then concatenate last_name!
    strcpy(full_name, last_name);
    strcat(full_name, " ");
    strcat(full_name, first_name);

    printf("Name: %s\n", full_name);

    return 0;
}
