#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *new_int_array(int length)
{
    return (int *)malloc(sizeof(int) * length);
}

void fill_rand(int *data, int length, int lower, int upper)
{
    for (int i = 0; i < length; i++) {
        data[i] = rand() % (upper - lower + 1) + lower;
    }
}

void print_array(int *data, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", data[i * width + j]);
        }
        printf("\n");
    }
}

void multiply_matrix_vector(int *result, int *matrix, int *vector, int m, int n)
{
    for (int i = 0; i < m; i++) {
        // sums the products and stores in result vector
        result[i] = 0;
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i * n + j] * vector[j];
        }
    }
}

void multiply_matrix(int *result, int *matrix1, int *matrix2, int m, int n, int p)
{
    // iterates through each column of result
    for (int k = 0; k < p; k++) {
        for (int i = 0; i < m; i++) {
            // sums the products and stores in a result entry
            result[i * p + k] = 0;
            for (int j = 0; j < n; j++) {
                result[i * p + k] += matrix1[i * n + j] * matrix2[j * p + k];
            }
        }
    }
}

int main()
{
    // gets a number from user
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    // seeds the randomizer
    srand((unsigned)time(NULL));

    // Question (a)
    {
        // allocates arrays
        int *matrix = new_int_array(n * n);
        int *vector = new_int_array(n);
        int *result = new_int_array(n);

        // fills arrays
        fill_rand(matrix, n * n, 0, 9);
        fill_rand(vector, n, 0, 9);

        // vector-matrix multiplication
        multiply_matrix_vector(result, matrix, vector, n, n);

        // displays result
        printf("\n\nQuestion (a) - Vector-matrix multiplication\n");
        printf("\nmatrix =\n");
        print_array(matrix, n, n);
        printf("\nvector =\n");
        print_array(vector, n, 1);
        printf("\nmatrix * vector =\n");
        print_array(result, n, 1);

        // free memory
        free(matrix);
        free(vector);
        free(result);
    }

    // Question (b)
    {
        // allocates arrays
        int *matrix1 = new_int_array(n * n);
        int *matrix2 = new_int_array(n * n);
        int *result = new_int_array(n * n);

        // fills arrays
        fill_rand(matrix1, n * n, 0, 9);
        fill_rand(matrix2, n * n, 0, 9);

        // Matrix-matrix multiplication
        multiply_matrix(result, matrix1, matrix2, n, n, n);

        // displays result
        printf("\n\nQuestion (b) - Matrix-matrix multiplication\n");
        printf("\nmatrix1 =\n");
        print_array(matrix1, n, n);
        printf("\nmatrix2 =\n");
        print_array(matrix2, n, n);
        printf("\nmatrix1 * matrix2 =\n");
        print_array(result, n, n);

        // free memory
        free(matrix1);
        free(matrix2);
        free(result);
    }

    return 0;
}