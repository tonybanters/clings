// Exercise 055: Struct Assignment and Copying
//
// In C, you can assign structs directly!
//   struct Point p1 = {1, 2};
//   struct Point p2 = p1;  // Copies all fields!
//
// But be careful with pointers inside structs!
// That's a "shallow copy" - both point to same data.
//
// EXPECTED: Original point: (10, 20)
// EXPECTED: Copied point: (10, 20)
// EXPECTED: Modified original: (30, 40)
// EXPECTED: Copy unchanged: (10, 20)
// HINT: Understand struct assignment, shallow vs deep copy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
    int x;
    int y;
};

struct Person {
    char *name;  // Pointer!
    int age;
};

int main(void) {
    // Struct assignment works!
    struct Point p1 = {10, 20};
    struct Point p2 = p1;  // Copies x and y

    printf("Original point: (%d, %d)\n", p1.x, p1.y);
    printf("Copied point: (%d, %d)\n", p2.x, p2.y);

    // Modifying p1 doesn't affect p2
    p1.x = 30;
    p1.y = 40;

    printf("Modified original: (%d, %d)\n", p1.x, p1.y);
    // TODO: Fix this!
    printf("Copy unchanged: (%d, %d)\n", p1.x, p1.y);

    // Warning: shallow copy with pointers!
    struct Person person1;
    person1.name = malloc(20);
    strcpy(person1.name, "Alice");
    person1.age = 25;

    struct Person person2 = person1;  // Shallow copy!
    // TODO: Both person1.name and person2.name point to SAME memory!
    // This is usually not what you want!

    free(person1.name);
    // person2.name is now dangling pointer! Don't use it!

    return 0;
}
