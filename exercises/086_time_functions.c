// Exercise 086: Working with Time
//
// C provides time functions in time.h!
//
// time(NULL) - get current time
// localtime() - convert to local time
// strftime() - format time as string
//
// EXPECTED: Current year: 2024 (or later)
// EXPECTED: Month is between 1 and 12
// EXPECTED: Formatted time printed
// HINT: Use time(), localtime(), strftime()

#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now;
    // TODO: Fix - should pass &now, not NULL!
    time(NULL);

    struct tm *local = localtime(&now);

    // tm_year is years since 1900
    // TODO: Fix - should add 1900 to tm_year!
    int year = local->tm_year;
    printf("Current year: %d\n", year);

    // tm_mon is 0-11, so add 1 for 1-12
    int month = local->tm_mon + 1;
    printf("Month is between 1 and 12\n");

    char buffer[80];
    // TODO: Fix - should use local, not &now!
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &now);
    printf("Formatted time printed\n");

    return 0;
}
