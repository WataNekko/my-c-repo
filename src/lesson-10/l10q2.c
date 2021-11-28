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

float average(int *data, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return (float)sum / length;
}

int max(int *data, int length)
{
    int max = data[0]; // initializes with the first element.
                       // If length is 0, this returns an undefined value.
    for (int i = 1; i < length; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }
    return max;
}

int min(int *data, int length)
{
    int min = data[0]; // initializes with the first element.
                       // If length is 0, this returns an undefined value.
    for (int i = 1; i < length; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }
    return min;
}

int check(int *data, int length, int value)
{
    for (int i = 0; i < length; i++) {
        if (data[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    // gets a number from user
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    // seeds the randomizer
    srand((unsigned)time(NULL));

    // creates array
    int *integers = new_int_array(n);
    fill_rand(integers, n, 0, 9);

    // displays functions result
    printf("integers = ");
    print_array(integers, 1, n);
    putchar('\n');

    // average
    printf("average(integers)  = %.1f\n\n", average(integers, n));

    // min max
    printf("max(integers)      = %d\n", max(integers, n));
    printf("min(integers)      = %d\n\n", min(integers, n));

    // check
    printf("check(integers, 8) = %s\n", check(integers, n, 8) ? "true" : "false");
    printf("check(integers, 9) = %s\n\n", check(integers, n, 9) ? "true" : "false");

    // free memory
    free(integers);

    return 0;
}