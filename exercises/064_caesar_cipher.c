// Exercise 064: Caesar Cipher - Fun Encryption!
//
// Caesar cipher shifts each letter by a fixed amount.
//
// Example with shift 3:
//   'A' -> 'D', 'B' -> 'E', ..., 'Z' -> 'C'
//
// This is a fun, easier exercise!
//
// EXPECTED: Original: HELLO
// EXPECTED: Encrypted: KHOOR
// EXPECTED: Decrypted: HELLO
// HINT: Add shift to character, handle wrap-around with modulo

#include <stdio.h>
#include <ctype.h>

void caesar_encrypt(char *text, int shift) {
    while (*text != '\0') {
        if (isupper(*text)) {
            // TODO: Fix formula - should be (*text - 'A' + shift) % 26 + 'A'!
            *text = (*text - 'A' + shift) + 'A';
        } else if (islower(*text)) {
            *text = (*text - 'a' + shift) % 26 + 'a';
        }
        text++;
    }
}

void caesar_decrypt(char *text, int shift) {
    // Decrypting is just encrypting with negative shift!
    // TODO: Call caesar_encrypt with -shift!
    caesar_encrypt(text, shift);
}

int main(void) {
    char message1[] = "HELLO";
    char message2[] = "KHOOR";

    printf("Original: %s\n", message1);

    caesar_encrypt(message1, 3);
    printf("Encrypted: %s\n", message1);

    caesar_decrypt(message2, 3);
    // TODO: Fix - should print message2, not message1!
    printf("Decrypted: %s\n", message1);

    return 0;
}
