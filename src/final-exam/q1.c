#include <stdio.h>

double f(double x)
{
    return x / 2 * (1 + x + 0.04 * x * x * x);
}

int main()
{
    printf("f(0.5) = %lf\n", f(0.5));
    printf("f(1.5) = %lf\n", f(1.5));
    return 0;
}