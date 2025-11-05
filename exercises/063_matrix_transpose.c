// Exercise 063: Matrix Transpose
//
// Transpose a matrix (swap rows and columns).
//
// Example:
//   [1 2 3]      [1 4]
//   [4 5 6]  =>  [2 5]
//                [3 6]
//
// EXPECTED: Original matrix:
// EXPECTED: 1 2 3
// EXPECTED: 4 5 6
// EXPECTED: Transposed matrix:
// EXPECTED: 1 4
// EXPECTED: 2 5
// EXPECTED: 3 6
// HINT: result[j][i] = matrix[i][j]

#include <stdio.h>

void transpose(int src[][3], int dest[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // TODO: Fix indices - should be dest[j][i] = src[i][j]!
            dest[i][j] = src[i][j];
        }
    }
}

int main(void) {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int transposed[3][2];

    printf("Original matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    transpose(matrix, transposed, 2, 3);

    printf("Transposed matrix:\n");
    // TODO: Fix dimensions - should be 3 rows, 2 cols!
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
