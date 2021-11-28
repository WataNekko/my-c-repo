#include <stdio.h>

// some cool documentation
void integrate_arr(int data[], int result[], int length)
{
	if (length > 0) {
		result[0] = data[0];
		for (int i = 1; i < length; i++) {
			result[i] = result[i - 1] + data[i];
		}
	}
}

void disp(int arr[], int length)
{
	printf("[ ");
	for (int i = 0; i < length; i++) {
		printf("%2d ", arr[i]);
	}
	printf("]\n");
}

int main()
{
	int data[10] = { 1, 8, 5, 7, 3, 5, 8, 3, 2, 9 };
	int integral_arr[10];

	integrate_arr(data, integral_arr, 10);
	printf("data                  = "); disp(data, 10);
	printf("integral_arr          = "); disp(integral_arr, 10);
	printf("sum from index 3 to 6 = %d\n", integral_arr[6] - integral_arr[3]);

	return 0;
}
