#include <math.h>
#include <stdio.h>

// some docstring
void hstack(int arr_a[], int arr_b[], int result[], int length_a, int length_b)
{
	for (int i = 0; i < length_a; i++) {
		result[i] = arr_a[i];
	}
	for (int i = 0; i < length_b; i++) {
		result[length_a + i] = arr_b[i];
	}
}

// docstring
void clip(int data[], int length, int min, int max)
{
	for (int i = 0; i < length; i++) {
		if (data[i] < min) {
			data[i] = min;
		}
		else if (data[i] > max) {
			data[i] = max;
		}
	}
}

// some more docstring
void square_root(double data[], double result[], int length)
{
	for (int i = 0; i < length; i++) {
		result[i] = sqrt(data[i]);
	}
}

void disp(int arr[], int length)
{
	printf("[ ");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void disp_d(double arr[], int length)
{
	printf("[ ");
	for (int i = 0; i < length; i++) {
		printf("%.1lf ", arr[i]);
	}
	printf("]\n");
}

int main()
{
	// hstack
	int arr_1[] = { 1, 2, 3 };
	int arr_2[] = { 4, 5, 6 };
	int intbuffer[10];

	printf("hstack:\n");
	disp(arr_1, 3);
	disp(arr_2, 3);
	hstack(arr_1, arr_2, intbuffer, 3, 3);
	disp(intbuffer, 6);

	// clip
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	printf("\nclip:\n");
	disp(data, 8);
	clip(data, 8, 3, 6);
	disp(data, 8);

	// sqrt
	double data_d[] = { 1, 2, 3, 4 };

	printf("\nsqrt:\n");
	disp_d(data_d, 4);
	square_root(data_d, data_d, 4);
	disp_d(data_d, 4);

	return 0;
}
