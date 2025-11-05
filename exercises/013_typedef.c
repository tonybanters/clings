// Exercise 013: Typedef
//
// typedef creates an alias for a type, making code more readable.
//
// Instead of writing "struct Person" everywhere, we can use typedef:
//   typedef struct Person Person;
//
// Or combine them:
//   typedef struct { ... } TypeName;
//
// typedef also works with primitive types:
//   typedef unsigned int uint;
//
// Fix THREE typedef-related bugs!
//
// EXPECTED: Point at (10, 20)
// EXPECTED: Distance from origin: 22
// EXPECTED: Unsigned value: 42
// HINT: Add typedef keywords and use the correct type names

#include <stdio.h>

struct Point {
    int x;
    int y;
};  // TODO: Add typedef to make "Point" work!

// TODO: Create a typedef for "unsigned int" called "uint"

int main(void) {
    Point p = {10, 20};  // This should work without "struct" keyword

    printf("Point at (%d, %d)\n", p.x, p.y);

    // Calculate distance from origin (using integer math)
    struct Point origin = {0, 0};  // TODO: Use the typedef'd name "Point" instead!
    int dist = (p.x - origin.x) + (p.y - origin.y);

    printf("Distance from origin: %d\n", dist);

    // Use our uint typedef
    uint value = 42;
    printf("Unsigned value: %u\n", value);

    return 0;
}
