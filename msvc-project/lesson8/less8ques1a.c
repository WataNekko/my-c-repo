#include <stdio.h>

// some doc about this function...
void arr_max(int result[], int m, int n, int arr[m][n], int axis)
{
	if (axis == 0) {
		// iterates through each column
		for (int j = 0; j < n; j++) {
			// finds max of each column
			result[j] = arr[0][j]; // initializes to the first element of the column
			for (int i = 1; i < m; i++) {
				if (result[j] < arr[i][j]) {
					result[j] = arr[i][j];
				}
			}
		}
	}
	else {
		// iterates through each row
		for (int i = 0; i < m; i++) {
			// finds max of each row
			result[i] = arr[i][0]; // initializes to the first element of the row
			for (int j = 1; j < n; j++) {
				if (result[i] < arr[i][j]) {
					result[i] = arr[i][j];
				}
			}
		}
	}
}

// some other doc about this function...
void arr_min(int result[], int m, int n, int arr[m][n], int axis)
{
	if (axis == 0) {
		// iterates through each column
		for (int j = 0; j < n; j++) {
			// finds min of each column
			result[j] = arr[0][j]; // initializes to the first element of the column
			for (int i = 1; i < m; i++) {
				if (result[j] > arr[i][j]) {
					result[j] = arr[i][j];
				}
			}
		}
	}
	else {
		// iterates through each row
		for (int i = 0; i < m; i++) {
			// finds min of each row
			result[i] = arr[i][0]; // initializes to the first element of the row
			for (int j = 1; j < n; j++) {
				if (result[i] > arr[i][j]) {
					result[i] = arr[i][j];
				}
			}
		}
	}
}

void disp(int m, int n, int arr[m][n])
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int buffer[3];

	printf("arr =\n");
	disp(3, 2, arr);

	// max
	printf("\nmax(arr, axis=0) =\n");
	arr_max(buffer, 3, 2, arr, 0);
	disp(1, 2, (int (*)[2])buffer);

	printf("max(arr, axis=1) =\n");
	arr_max(buffer, 3, 2, arr, 1);
	disp(3, 1, (int (*)[1])buffer);

	// min
	printf("\nmin(arr, axis=0) =\n");
	arr_min(buffer, 3, 2, arr, 0);
	disp(1, 2, (int (*)[2])buffer);

	printf("min(arr, axis=1) =\n");
	arr_min(buffer, 3, 2, arr, 1);
	disp(3, 1, (int (*)[1])buffer);

	return 0;
}