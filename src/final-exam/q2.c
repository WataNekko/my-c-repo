#include <math.h>
#include <stdio.h>

double approx_log(double x, int n)
{
    double result = 0;
    for (int i = 1; i <= n; i++) {
        result -= pow(x, i) / i;
    }
    return result;
}

int main()
{
    printf("approx_log(0.5, n=10) = %lf\n", approx_log(0.5, 10));
    printf("approx_log(0.5, n=100) = %lf\n", approx_log(0.5, 100));
    return 0;
}