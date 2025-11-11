// Exercise 032: Struct Padding and Alignment
//
// Compilers add padding to structs for memory alignment.
//
// Example:
//   struct Bad {
//       char c;   // 1 byte
//       int i;    // 4 bytes (but needs 4-byte alignment!)
//   };  // Size: 8 bytes (not 5!) due to 3 bytes of padding
//
// Rules:
//   - Members aligned to their size (int on 4-byte boundary)
//   - Struct size is multiple of largest alignment
//   - Order matters! Rearranging can save space
//
// Use #pragma pack(1) to remove padding (not recommended!)
//
// Fix THREE struct padding bugs!
//
// EXPECTED: Bad layout size: 12 (wastes 6 bytes)
// EXPECTED: Good layout size: 8 (wastes 2 bytes)
// EXPECTED: Packed size: 6 (no padding)
// HINT: Understand alignment, reorder fields efficiently, know padding rules

#include <stdio.h>

// Bad layout: lots of padding!
struct BadLayout {
    char a;     // 1 byte + 3 bytes padding
    int b;      // 4 bytes
    char c;     // 1 byte + 3 bytes padding
};

// Good layout: minimizes padding
struct GoodLayout {
    int b;      // 4 bytes
    char a;     // 1 byte
    char c;     // 1 byte + 2 bytes padding
};

// Packed: no padding (use with caution!)
#pragma pack(push, 1)
struct PackedLayout {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
};
#pragma pack(pop)

int main(void) {
    printf("Bad layout size: %zu ", sizeof(struct BadLayout));
    // TODO: Fix this! (char + padding + int + char + padding)
    printf("(wastes 6 bytes)\n");

    printf("Good layout size: %zu ", sizeof(struct GoodLayout));
    // TODO: Fix this! (int + char + char + padding)
    printf("(wastes 2 bytes)\n");

    // TODO: Fix this!
    printf("Packed size: %zu (no padding)\n", sizeof(struct BadLayout));

    // Demonstrate the difference
    struct BadLayout bad;
    struct GoodLayout good;

    printf("\nMember offsets:\n");
    printf("BadLayout:  a=%zu, b=%zu, c=%zu\n",
           (size_t)&bad.a - (size_t)&bad,
           (size_t)&bad.b - (size_t)&bad,
           (size_t)&bad.c - (size_t)&bad);

    printf("GoodLayout: b=%zu, a=%zu, c=%zu\n",
           (size_t)&good.b - (size_t)&good,
           (size_t)&good.a - (size_t)&good,
           (size_t)&good.c - (size_t)&good);

    return 0;
}
