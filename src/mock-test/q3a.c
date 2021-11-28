#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sum_row(int *result, int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        result[i] = 0; // initialize sum to 0
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i * cols + j]; // sum the rows
        }
    }
}

//------ utility functions ------
void fill_array_09(int *arr, int length)
{
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 10;
    }
}

void print_matrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}
//-------------------------------

int main()
{
    srand((unsigned)time(NULL)); // seed the randomizer

    // variables
    int rows = 3;
    int cols = 3;
    int *matrix;
    int *result;

    // create matrix
    result = (int *)malloc(sizeof(int) * rows);
    matrix = (int *)malloc(sizeof(int) * rows * cols);
    fill_array_09(matrix, rows * cols);

    // sum rows
    sum_row(result, matrix, rows, cols);

    printf("x =\n");
    print_matrix(matrix, rows, cols);
    printf("\nsum_row(x) =\n");
    print_matrix(result, rows, 1);

    // clean up
    free(matrix);
    free(result);

    return 0;
}