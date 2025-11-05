// Exercise 018: Enumerations
//
// Enums let you define a set of named integer constants.
// They make code more readable than using raw numbers!
//
// Syntax:
//   enum Name { VALUE1, VALUE2, VALUE3 };
//
// By default, values start at 0 and increment by 1.
// You can also assign specific values:
//   enum Status { OK = 0, ERROR = -1, PENDING = 100 };
//
// Enums are just integers under the hood!
//
// Fix THREE enum-related bugs!
//
// EXPECTED: Today is Wednesday (day 3)
// EXPECTED: Color: Green (value 1)
// EXPECTED: Status: Ready (value 2)
// HINT: Add missing values, fix assignments, and understand enum numbering

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

enum Color {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

enum Status {
    IDLE = 0,
    RUNNING,  // This will be 1
    READY,    // This will be 2
    STOPPED = 5
};

int main(void) {
    enum Day today = WEDNESDAY;

    printf("Today is ");
    switch (today) {
        case SUNDAY:    printf("Sunday"); break;
        case MONDAY:    printf("Monday"); break;
        case TUESDAY:   printf("Tuesday"); break;
        case WEDNESDAY: printf("Wednesday"); break;
        case THURSDAY:  printf("Thursday"); break;
        case FRIDAY:    printf("Friday"); break;
        case SATURDAY:  printf("Saturday"); break;
    }
    printf(" (day %d)\n", today);

    // Test enum values
    enum Color color = GREEN;
    printf("Color: ");
    // TODO: Fix this comparison - should check if color == GREEN
    if (color = RED) {
        printf("Red");
    } else if (color == GREEN) {
        printf("Green");
    } else {
        printf("Blue");
    }
    printf(" (value %d)\n", color);

    // Test enum with custom values
    enum Status status = READY;
    printf("Status: ");
    switch (status) {
        case IDLE:    printf("Idle"); break;
        case RUNNING: printf("Running"); break;
        case READY:   printf("Ready"); break;
        case STOPPED: printf("Stopped"); break;
        // TODO: Add a default case to handle unexpected values
    }
    printf(" (value %d)\n", status);

    return 0;
}
