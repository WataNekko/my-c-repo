//#define __COMPILE__
#ifdef __COMPILE__

#include <stdio.h>
#include <math.h>

double taylor_sinh(double x, int nterms)
{
	double result = x;
	size_t factorial = 1;

	for (int i = 3; i <= nterms; i += 2) {
		factorial *= (i - 1) * i;
		result += pow(x, i) / factorial;
	}

	return result;
}

int main()
{
	printf("%lf\n", taylor_sinh(4, 15));
	printf("%lf\n", sinh(4));
	return 0;
}

#endif
