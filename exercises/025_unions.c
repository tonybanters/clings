// Exercise 025: Unions
//
// A union is like a struct, but all members share the same memory.
// Only one member can hold a value at a time!
//
// Declaration:
//   union Data {
//       int i;
//       float f;
//       char str[20];
//   };
//
// Size: sizeof(union) = size of largest member
//
// Unions are useful for:
//   - Type punning (viewing same data as different types)
//   - Memory-efficient variants
//   - Low-level programming
//
// Fix THREE union-related bugs!
//
// EXPECTED: Integer: 42
// EXPECTED: Float: 3.14
// EXPECTED: String: Hello
// EXPECTED: Last value in union: Hello (string)
// EXPECTED: Union size: 20 (size of largest member)
// HINT: Understand that unions share memory, only one value at a time

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main(void) {
    union Data data;

    // Store and print integer
    data.i = 42;
    printf("Integer: %d\n", data.i);

    // Store and print float (overwrites integer!)
    data.f = 3.14;
    printf("Float: %.2f\n", data.f);

    // Store and print string (overwrites float!)
    strcpy(data.str, "Hello");
    printf("String: %s\n", data.str);

    // TODO: Fix this!
    printf("Last value in union: ");
    // After storing "Hello", i and f contain garbage!
    if (data.i == 42) {
        printf("%d (integer)\n", data.i);
    } else if (data.f == 3.14) {
        printf("%.2f (float)\n", data.f);
    } else {
        printf("%s (string)\n", data.str);
    }

    // TODO: Fix this!
    printf("Union size: %zu (size of largest member)\n", sizeof(data));

    // Tagged union pattern (union + enum for type safety)
    enum DataType { TYPE_INT, TYPE_FLOAT, TYPE_STRING };

    struct TaggedData {
        enum DataType type;
        union Data value;
    };

    struct TaggedData td;
    td.type = TYPE_STRING;  // TODO: Fix this!
    td.value.i = 100;

    return 0;
}
