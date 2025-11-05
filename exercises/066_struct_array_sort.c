// Exercise 066: Sorting Array of Structs
//
// Sort an array of structs using qsort() from stdlib!
//
// qsort() needs a comparison function:
//   int compare(const void *a, const void *b)
//   Returns: negative if a < b, 0 if equal, positive if a > b
//
// EXPECTED: Unsorted:
// EXPECTED: Alice: 25
// EXPECTED: Charlie: 20
// EXPECTED: Bob: 30
// EXPECTED: Sorted by age:
// EXPECTED: Charlie: 20
// EXPECTED: Alice: 25
// EXPECTED: Bob: 30
// HINT: Cast void* to struct, return age comparison

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
} Person;

int compare_by_age(const void *a, const void *b) {
    // TODO: Cast to Person* and compare ages!
    // Hint: Person *pa = (Person *)a;
    //       Person *pb = (Person *)b;
    //       return pa->age - pb->age;
    return 0;
}

int main(void) {
    Person people[] = {
        {"Alice", 25},
        {"Charlie", 20},
        {"Bob", 30}
    };

    int size = sizeof(people) / sizeof(people[0]);

    printf("Unsorted:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    // TODO: Call qsort with correct parameters!
    // Hint: qsort(people, size, sizeof(Person), compare_by_age);

    printf("Sorted by age:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    return 0;
}
