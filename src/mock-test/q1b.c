#include <math.h>
#include <stdio.h>

double estimate_pi(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i + 1) / (2 * i - 1);
    }
    return 4 * sum;
}

int main()
{
    printf("PI is approximately %lf\n", estimate_pi(100000));
    return 0;
}