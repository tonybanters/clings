// Exercise 036: 2D Arrays and Multi-dimensional Arrays
//
// 2D arrays in C are arrays of arrays.
//
// Declaration:
//   int arr[3][4];  // 3 rows, 4 columns
//
// Memory layout is row-major (rows stored contiguously).
//
// Access:
//   arr[i][j]      // element at row i, column j
//   arr[i]         // pointer to row i
//
// Dynamic 2D arrays need array of pointers:
//   int **matrix = malloc(rows * sizeof(int *));
//   for (i = 0; i < rows; i++)
//       matrix[i] = malloc(cols * sizeof(int));
//
// Fix THREE 2D array bugs!
//
// EXPECTED: Static 2D array:
// EXPECTED: 1 2 3
// EXPECTED: 4 5 6
// EXPECTED: Sum: 21
// EXPECTED: Element at [1][2]: 6
// HINT: Check array dimensions, loop bounds, access patterns

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Static 2D array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("Static 2D array:\n");
    // TODO: Fix this!
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        // TODO: Fix this!
        for (int j = 0; j < 2; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum: %d\n", sum);

    // Access specific element
    // TODO: Fix this!
    printf("Element at [1][2]: %d\n", matrix[2][1]);

    // Dynamic 2D array
    int rows = 3, cols = 4;
    int **dynamic = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dynamic[i] = malloc(cols * sizeof(int));
    }

    // Initialize
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dynamic[i][j] = count++;
        }
    }

    // Free (must free in reverse order!)
    for (int i = 0; i < rows; i++) {
        free(dynamic[i]);
    }
    free(dynamic);

    return 0;
}
