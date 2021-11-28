#include <stdio.h>
#include <stdlib.h>

int *alloc_rand_arr(int length)
{
    int *arr = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 10;
    }
    return arr;
}

// Performs element-wise multiplication on two arrays and stores the result in 'result'.
void arr_mult(int *result, int *arr1, int *arr2, int length)
{
    for (int i = 0; i < length; i++) {
        result[i] = arr1[i] * arr2[i];
    }
}

// Performs dot product operation on two arrays and returns the result.
int arr_dot(int *arr1, int *arr2, int length)
{
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += arr1[i] * arr2[i];
    }
    return result;
}

// Finds the maximum value in an int array.
int arr_max(int *arr, int length)
{
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void print_arr(int *arr, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
