// Exercise 018: Enumerations
//
// Enums let you define a set of named integer constants.
// They make code more readable than using raw numbers!
//
// Syntax:
//   enum Name { VALUE1, VALUE2, VALUE3 };
//
// By default, values start at 0 and increment by 1.
//
// EXPECTED: Today is Wednesday
// HINT: Add WEDNESDAY to the enum (it should be the 4th value)

#include <stdio.h>

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    // TODO: Add WEDNESDAY here!
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main(void) {
    enum Day today = WEDNESDAY;

    printf("Today is ");
    switch (today) {
        case SUNDAY:    printf("Sunday\n"); break;
        case MONDAY:    printf("Monday\n"); break;
        case TUESDAY:   printf("Tuesday\n"); break;
        case WEDNESDAY: printf("Wednesday\n"); break;
        case THURSDAY:  printf("Thursday\n"); break;
        case FRIDAY:    printf("Friday\n"); break;
        case SATURDAY:  printf("Saturday\n"); break;
    }

    return 0;
}
