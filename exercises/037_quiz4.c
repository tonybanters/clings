// Exercise 037: Quiz 4 - Structs & Memory
//
// This quiz combines:
//   - Structs and typedef
//   - Dynamic memory allocation
//   - Linked structures
//   - Memory management
//
// Create a simple student database using structs and dynamic memory!
//
// EXPECTED: Created student: Alice (ID: 1, GPA: 3.80)
// EXPECTED: Created student: Bob (ID: 2, GPA: 3.50)
// EXPECTED: Created student: Charlie (ID: 3, GPA: 3.90)
// EXPECTED: Average GPA: 3.73
// EXPECTED: Freed all memory
// HINT: Complete struct, allocate memory, calculate average, free everything

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    float gpa;
    // TODO: Add pointer to next student for linked list!
} Student;

// Create a new student
Student* create_student(int id, const char *name, float gpa) {
    // TODO: Allocate memory for new student!
    Student *s = NULL;

    if (s == NULL) {
        return NULL;
    }

    s->id = id;
    strcpy(s->name, name);
    s->gpa = gpa;
    s->next = NULL;

    printf("Created student: %s (ID: %d, GPA: %.2f)\n", name, id, gpa);
    return s;
}

// Calculate average GPA
float calculate_average_gpa(Student *head) {
    if (head == NULL) {
        return 0.0;
    }

    float sum = 0.0;
    int count = 0;
    Student *current = head;

    // TODO: Traverse list and calculate average!

    return sum / count;
}

// Free all students in list
void free_students(Student *head) {
    // TODO: Implement this function to free all students!
    // Hint: Use temporary pointer to avoid losing reference
}

int main(void) {
    // Create students
    Student *alice = create_student(1, "Alice", 3.8);
    Student *bob = create_student(2, "Bob", 3.5);
    Student *charlie = create_student(3, "Charlie", 3.9);

    // Link them
    alice->next = bob;
    bob->next = charlie;

    // Calculate average
    float avg = calculate_average_gpa(alice);
    printf("Average GPA: %.2f\n", avg);

    // Free memory
    free_students(alice);
    printf("Freed all memory\n");

    return 0;
}
