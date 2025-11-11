// Exercise 074: Bitwise Flags
//
// Use bitwise operations to store multiple boolean flags
// in a single integer! Common in systems programming.
//
// Operations:
//   Set flag:    flags |= FLAG
//   Clear flag:  flags &= ~FLAG
//   Toggle flag: flags ^= FLAG
//   Check flag:  flags & FLAG
//
// EXPECTED: Initial: Read
// EXPECTED: After adding Write: Read Write
// EXPECTED: After removing Read: Write
// EXPECTED: After toggling Execute: Write Execute
// HINT: Use bitwise OR to set, AND with NOT to clear

#include <stdio.h>

#define FLAG_READ    (1 << 0)  // 0001 = 1
#define FLAG_WRITE   (1 << 1)  // 0010 = 2
#define FLAG_EXECUTE (1 << 2)  // 0100 = 4

void print_flags(unsigned int flags) {
    if (flags & FLAG_READ) printf("Read ");
    if (flags & FLAG_WRITE) printf("Write ");
    if (flags & FLAG_EXECUTE) printf("Execute ");
    printf("\n");
}

int main(void) {
    unsigned int flags = FLAG_READ;

    printf("Initial: ");
    print_flags(flags);

    // Add write permission
    // TODO: Fix this!
    flags += FLAG_WRITE;
    printf("After adding Write: ");
    print_flags(flags);

    // Remove read permission
    // TODO: Fix this!
    flags = flags | FLAG_READ;
    printf("After removing Read: ");
    print_flags(flags);

    // Toggle execute permission
    // TODO: Fix this!
    flags |= FLAG_EXECUTE;
    printf("After toggling Execute: ");
    print_flags(flags);

    return 0;
}
