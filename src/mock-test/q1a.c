#include <math.h>
#include <stdio.h>

double f(double x)
{
    return 1 + 1 / (1 + exp(-x));
}

int main()
{
    printf("f(0) = %lf\n", f(0));
    printf("f(1) = %lf\n", f(1));
    return 0;
}