// Exercise 012: Structures
//
// Structs let you group related data together into a single type.
//
// Definition:
//   struct Name {
//       type field1;
//       type field2;
//   };
//
// Access fields with dot operator:
//   struct_variable.field_name
//
// Pointers to structs use arrow operator:
//   struct_pointer->field_name  (same as (*struct_pointer).field_name)
//
// Fix THREE struct-related bugs!
//
// EXPECTED: Person: Alice, Age: 30, Height: 5.50
// EXPECTED: Via pointer: Bob, Age: 25, Height: 6.00
// EXPECTED: Updated: Alice, Age: 31, Height: 5.50
// HINT: Complete struct definition, use correct operators, and pointer syntax

#include <stdio.h>

struct Person {
    char name[50];
    int age;
    // TODO: Add a 'height' field of type float here!
};

int main(void) {
    struct Person alice = {"Alice", 30, 5.5};
    struct Person bob = {"Bob", 25, 6.0};

    printf("Person: %s, Age: %d, Height: %.2f\n", alice.name, alice.age, alice.height);

    // Access via pointer
    struct Person *ptr = &bob;
    printf("Via pointer: %s, Age: %d, Height: %.2f\n", ptr.name, ptr.age, ptr.height);  // TODO: Fix - use arrow operator!

    // Modify through pointer
    ptr = &alice;
    ptr->age = 31;  // TODO: Fix - missing dereference or arrow!

    printf("Updated: %s, Age: %d, Height: %.2f\n", alice.name, alice.age, alice.height);

    return 0;
}
