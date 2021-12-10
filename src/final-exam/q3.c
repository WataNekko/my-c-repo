#include <stdio.h>
#include <stdlib.h>

int *create_data(int length)
{
    int *data = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        data[i] = rand() % 10;
    }
    return data;
}

void print_matrix(int *data, int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", data[(i * col) + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sum_row_odd(int *result, int *data, int row, int col)
{
    for (int i = 0; i < row; i++) {
        result[i] = 0; // initializes sum to 0
        for (int j = 0; j < col; j++) {
            if (data[i * col + j] % 2 == 1) {
                // sums the odd elements
                result[i] += data[i * col + j];
            }
        }
    }
}

int main()
{
    // test case 1
    {
        printf("Test case 1:\n\n");

        int row = 3, col = 3;

        // create 1D memory
        int *matrix = create_data(row * col);

        // print matrix
        print_matrix(matrix, row, col);

        // sum the odd elements of each row
        int *res = malloc(sizeof(int) * row);
        sum_row_odd(res, matrix, row, col);

        printf("res =\n");
        print_matrix(res, row, 1);

        //free memory
        free(matrix);
        free(res);
    }

    // test case 2
    {
        printf("Test case 2:\n\n");

        int row = 4, col = 3;

        // create 1D memory
        int *matrix = create_data(row * col);

        // print matrix
        print_matrix(matrix, row, col);

        // sum the odd elements of each row
        int *res = malloc(sizeof(int) * row);
        sum_row_odd(res, matrix, row, col);

        printf("res =\n");
        print_matrix(res, row, 1);

        //free memory
        free(matrix);
        free(res);
    }

    return 0;
}
