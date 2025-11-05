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
// Don't forget the break statements! Without them, execution "falls through"
// to the next case (sometimes useful, but usually a bug!)
//
// Fix THREE switch statement bugs!
//
// EXPECTED: Grade B: Good
// EXPECTED: Day 3: Wednesday
// EXPECTED: Fruit: Apple is red
// HINT: Add missing cases, fix fall-through bugs, check switch values

#include <stdio.h>

int main(void) {
    // Test 1: Grade with missing case
    char grade = 'B';

    switch (grade) {
        case 'A':
            printf("Grade A: Excellent\n");
            break;
        // TODO: Add case for 'B' that prints "Grade B: Good"
        case 'C':
            printf("Grade C: Average\n");
            break;
        default:
            printf("Grade: Unknown\n");
    }

    // Test 2: Day of week with fall-through bug
    int day = 3;  // Wednesday

    switch (day) {
        case 1:
            printf("Day 1: Monday\n");
            break;
        case 2:
            printf("Day 2: Tuesday\n");
            break;
        case 3:
            printf("Day 3: Wednesday\n");
            // TODO: Missing break statement! This causes fall-through
        case 4:
            printf("Day 4: Thursday\n");
            break;
        default:
            printf("Invalid day\n");
    }

    // Test 3: String comparison (common mistake!)
    char fruit[] = "Apple";

    // TODO: This is WRONG! Can't switch on strings in C!
    // Change to use the first character: fruit[0]
    switch (fruit) {
        case 'A':
            printf("Fruit: Apple is red\n");
            break;
        case 'B':
            printf("Fruit: Banana is yellow\n");
            break;
        default:
            printf("Unknown fruit\n");
    }

    return 0;
}
