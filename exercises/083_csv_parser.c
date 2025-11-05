// Exercise 083: Simple CSV Parser
//
// Parse comma-separated values from a string!
//
// CSV format: name,age,city
//
// EXPECTED: Record 1: Alice, 25, NYC
// EXPECTED: Record 2: Bob, 30, LA
// EXPECTED: Record 3: Charlie, 35, Chicago
// HINT: Use strtok with newline and comma delimiters

#include <stdio.h>
#include <string.h>

void parse_csv_line(char *line) {
    // TODO: Fix delimiter - should be "," not ";"!
    char *name = strtok(line, ";");
    char *age = strtok(NULL, ",");
    // TODO: Add strtok call to get city!
    char *city = NULL;

    if (name && age && city) {
        printf("%s, %s, %s\n", name, age, city);
    }
}

int main(void) {
    char data[] = "Alice,25,NYC\nBob,30,LA\nCharlie,35,Chicago";
    char *line = strtok(data, "\n");

    int record_num = 1;
    while (line != NULL) {
        printf("Record %d: ", record_num++);
        // Need to make a copy because parse_csv_line modifies the string
        char line_copy[100];
        strcpy(line_copy, line);
        parse_csv_line(line_copy);

        // TODO: Fix - should use NULL, not data!
        line = strtok(data, "\n");
    }

    return 0;
}
