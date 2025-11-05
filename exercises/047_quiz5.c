// Exercise 047: Quiz 5 - Data Structures & Algorithms
//
// This quiz combines:
//   - Arrays and searching
//   - Sorting algorithms
//   - Recursion
//   - Algorithm complexity
//
// Implement and compare different searching and sorting approaches!
//
// EXPECTED: Original array: 64 34 25 12 22 11 90
// EXPECTED: Sorted array: 11 12 22 25 34 64 90
// EXPECTED: Binary search for 25: Found at index 3
// EXPECTED: Binary search for 100: Not found
// EXPECTED: Factorial of 6: 720
// HINT: Implement sorting, searching, and recursion correctly

#include <stdio.h>

// Simple bubble sort (from exercise 044, but implement from scratch!)
void sort_array(int arr[], int size) {
    // TODO: Implement bubble sort!
    // Hint: nested loops, swap adjacent elements
}

// Binary search (requires sorted array!)
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // TODO: Implement comparison and adjustment logic!
    }

    return -1;  // Not found
}

// Recursive factorial
int factorial(int n) {
    // TODO: Implement base case and recursive case!
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    print_array(numbers, size);

    // Sort the array
    sort_array(numbers, size);

    printf("Sorted array: ");
    print_array(numbers, size);

    // Binary search
    int index = binary_search(numbers, size, 25);
    if (index != -1) {
        printf("Binary search for 25: Found at index %d\n", index);
    } else {
        printf("Binary search for 25: Not found\n");
    }

    index = binary_search(numbers, size, 100);
    if (index != -1) {
        printf("Binary search for 100: Found at index %d\n", index);
    } else {
        printf("Binary search for 100: Not found\n");
    }

    // Factorial
    printf("Factorial of 6: %d\n", factorial(6));

    return 0;
}
