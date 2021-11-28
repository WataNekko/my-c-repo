#include <math.h>
#include <stdio.h>

void softmax(double *result, double *x, int length)
{
    double max = x[0];
    double sum = 0;

    // finds max
    for (int i = 1; i < length; i++) {
        if (max < x[i]) {
            max = x[i];
        }
    }

    // gets sum
    for (int i = 0; i < length; i++) {
        result[i] = exp(x[i] - max);
        sum += result[i];
    }

    // softmax result
    for (int i = 0; i < length; i++) {
        result[i] /= sum;
    }
}

void print_array(double *arr, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%.2lf ", arr[i]);
    }
}

int main()
{
    double x1[] = {1., 2., 3.};
    double x2[] = {1001., 1002., 1003.};
    double result[3];

    softmax(result, x1, 3);
    printf("x1 = ");
    print_array(x1, 3);
    printf("\nsoftmax(x1) = ");
    print_array(result, 3);

    softmax(result, x2, 3);
    printf("\n\nx2 = ");
    print_array(x2, 3);
    printf("\nsoftmax(x2) = ");
    print_array(result, 3);

    return 0;
}
