#include <stdio.h>

void clip(int *array, int length, int min_value, int max_value)
{
    for (int i = 0; i < length; i++) {
        if (array[i] < min_value) {
            array[i] = min_value;
        }
        else if (array[i] > max_value) {
            array[i] = max_value;
        }
    }
}

void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    // test case 1
    {
        printf("Example 1:\n\n");

        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int length = 9, min = 3, max = 6;

        // print input
        printf("input:\nmin_value = %d, max_value = %d\nx = ", min, max);
        print_array(array, length);

        // result
        clip(array, length, min, max);
        printf("result:\nx = ");
        print_array(array, length);
    }

    // test case 2
    {
        printf("\n\nExample 2:\n\n");

        int array[] = {4, 12, 23, 4, 35, 16, 7};
        int length = 7, min = 11, max = 33;

        // print input
        printf("input:\nmin_value = %d, max_value = %d\nx = ", min, max);
        print_array(array, length);

        // result
        clip(array, length, min, max);
        printf("result:\nx = ");
        print_array(array, length);
    }

    return 0;
}
