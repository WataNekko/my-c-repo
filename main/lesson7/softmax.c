#include <stdio.h>
#include <math.h>

void softmax(double x[], double result[], size_t length)
{
	double max = x[0];
	double sum = 0;

	// finds max
	for (size_t i = 1; i < length; i++) {
		if (max < x[i]) {
			max = x[i];
		}
	}

	// gets sum
	for (size_t i = 0; i < length; i++) {
		result[i] = exp(x[i] - max);
		sum += result[i];
	}

	// softmax result
	for (size_t i = 0; i < length; i++) {
		result[i] /= sum;
	}
}

int main()
{
	double x[] = { 1., 1002., 1003. };
	softmax(x, x, 3);
	for (int i = 0; i < 3; i++) {
		printf("%lf\n", x[i]);
	}
}
