// Exercise 067: Number Base Conversion
//
// Convert decimal to binary, octal, and hexadecimal!
//
// Algorithm for binary:
//   1. Divide by 2, record remainder
//   2. Repeat with quotient
//   3. Read remainders in reverse
//
// EXPECTED: Decimal: 42
// EXPECTED: Binary: 101010
// EXPECTED: Octal: 52
// EXPECTED: Hexadecimal: 2A
// HINT: Use division and modulo, build string in reverse

#include <stdio.h>
#include <string.h>

void decimal_to_binary(int n, char *result) {
    if (n == 0) {
        strcpy(result, "0");
        return;
    }

    char temp[33];
    int i = 0;

    while (n > 0) {
        // TODO: Fix this!
        temp[i++] = (n / 2) + '0';
        n /= 2;
    }
    temp[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i; j++) {
        // TODO: Fix this!
        result[j] = temp[j];
    }
    result[i] = '\0';
}

int main(void) {
    int num = 42;
    char binary[33];

    printf("Decimal: %d\n", num);

    decimal_to_binary(num, binary);
    printf("Binary: %s\n", binary);

    // Built-in formatters make octal and hex easy!
    printf("Octal: %o\n", num);
    // TODO: Fix this!
    printf("Hexadecimal: %x\n", num);

    return 0;
}
