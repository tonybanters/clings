// Exercise 017: Switch Statements
//
// Switch statements provide a clean way to handle multiple conditions.
//
// Syntax:
//   switch (variable) {
//       case value1:
//           // code
//           break;
//       case value2:
//           // code
//           break;
//       default:
//           // code
//   }
//
// Don't forget the break statements!
//
// EXPECTED: Grade: B
// HINT: Add a case for 'B'

#include <stdio.h>

int main(void) {
    char grade = 'B';

    switch (grade) {
        case 'A':
            printf("Grade: A\n");
            break;
        // TODO: Add case for 'B'
        case 'C':
            printf("Grade: C\n");
            break;
        default:
            printf("Grade: Unknown\n");
    }

    return 0;
}
