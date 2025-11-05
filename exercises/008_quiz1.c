// Exercise 008: Quiz 1 - Basics Review
//
// Time to test what you've learned!
//
// This quiz combines:
//   - Variables and types
//   - Arithmetic operations
//   - Printf formatting
//   - Basic control flow
//
// Fix ALL the bugs to make this program work correctly!
//
// EXPECTED: Name: Alice, Age: 25
// EXPECTED: In 5 years: 30
// EXPECTED: Double age: 50
// EXPECTED: Age is greater than 18
// HINT: Check types, operators, format specifiers, and logic

#include <stdio.h>

int main(void) {
    // Personal information
    char name[] = "Alice";
    float age = 25;  // TODO: Fix type - age should be int!

    printf("Name: %s, Age: %d\n", name, age);

    // Calculate future age
    int years = 5;
    int future_age = age - years;  // TODO: Fix operator!

    printf("In %d years: %d\n", years, future_age);

    // Double the age
    int double_age = age + age;  // TODO: Fix - should multiply, not add!
    printf("Double age: %d\n", double_age);

    // Check if adult
    if (age > 18) {
        printf("Age is greater than 18\n");
    } else {
        printf("Age is 18 or less\n");
    }

    return 0;
}
