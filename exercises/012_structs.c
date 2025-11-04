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
// Access fields:
//   struct_variable.field_name
//
// Complete the struct definition!
//
// EXPECTED: Alice is 30 years old
// HINT: Add an age field of type int to the Person struct

#include <stdio.h>

struct Person {
    char name[50];
    // TODO: Add an 'age' field of type int here!
};

int main(void) {
    struct Person alice = {"Alice", 30};

    printf("%s is %d years old\n", alice.name, alice.age);
    return 0;
}
