// Exercise 076: Unions
//
// Unions let multiple members share the same memory!
// Only one member is valid at a time.
//
// Use case: Type-punning, variant types, memory saving
//
// EXPECTED: As int: 1094795585
// EXPECTED: As bytes: 65 66 67 68
// EXPECTED: Circle area: 78.50
// EXPECTED: Rectangle area: 24.00
// HINT: All union members share memory, accessing one affects others

#include <stdio.h>
#include <math.h>

union Data {
    int i;
    float f;
    char bytes[4];
};

typedef struct {
    enum { CIRCLE, RECTANGLE } type;
    union {
        struct { float radius; } circle;
        struct { float width, height; } rectangle;
    } shape;
} Shape;

int main(void) {
    union Data data;
    data.i = 0x44434241;  // "ABCD" in hex

    printf("As int: %d\n", data.i);
    printf("As bytes: ");
    for (int i = 0; i < 4; i++) {
        // TODO: Fix this!
        printf("%c ", data.bytes[i]);
    }
    printf("\n");

    // Shape examples
    Shape s1;
    s1.type = CIRCLE;
    s1.shape.circle.radius = 5.0f;
    // TODO: Fix this!
    float area1 = M_PI * s1.shape.circle.radius;
    printf("Circle area: %.2f\n", area1);

    Shape s2;
    // TODO: Fix this!
    s2.type = CIRCLE;
    s2.shape.rectangle.width = 4.0f;
    s2.shape.rectangle.height = 6.0f;
    float area2 = s2.shape.rectangle.width * s2.shape.rectangle.height;
    printf("Rectangle area: %.2f\n", area2);

    return 0;
}
