// Exercise 013: Typedef
//
// typedef creates an alias for a type, making code more readable.
//
// Instead of writing "struct Person" everywhere, we can use typedef:
//   typedef struct Person Person;
//
// Or combine them:
//   typedef struct Person { ... } Person;
//
// Fix the typedef so we can use "Point" instead of "struct Point"!
//
// EXPECTED: Point at (10, 20)
// HINT: Add typedef before struct, and Point after the closing brace

#include <stdio.h>

struct Point {
    int x;
    int y;
};  // TODO: Add typedef to make this work!

int main(void) {
    Point p = {10, 20};  // This should work without "struct" keyword

    printf("Point at (%d, %d)\n", p.x, p.y);
    return 0;
}
