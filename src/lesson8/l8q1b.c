#include <stdio.h>

// doc
void sum(int result[], int m, int n, int arr[m][n], int axis)
{
	if (axis == 0) {
		// iterates through each column
		for (int j = 0; j < n; j++) {
			// sums all elements of each column
			result[j] = 0;
			for (int i = 0; i < m; i++) {
				result[j] += arr[i][j];
			}
		}
	}
	else {
		// iterates through each row
		for (int i = 0; i < m; i++) {
			// sums all elements of each row
			result[i] = 0;
			for (int j = 0; j < n; j++) {
				result[i] += arr[i][j];
			}
		}
	}
}

// nice doc
int sum_all(int m, int n, int arr[m][n])
{
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

// this is documentation...
void transpose(int m, int n, int result[n][m], int arr[m][n])
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result[j][i] = arr[i][j];
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
	int arr[2][2] = { { 1, 2 }, { 3, 4 } };
	int buffer[4];

	printf("arr =\n");
	disp(2, 2, arr);

	// sum
	printf("\nsum(arr, axis=0) =\n");
	sum(buffer, 2, 2, arr, 0);
	disp(1, 2, (int (*)[2])buffer);

	printf("sum(arr, axis=1) =\n");
	sum(buffer, 2, 2, arr, 1);
	disp(2, 1, (int (*)[1])buffer);

	printf("sum_all(arr) = %d\n", sum_all(2, 2, arr));

	// transpose
	printf("\ntranspose(arr) =\n");
	transpose(2, 2, (int (*)[2])buffer, arr);
	disp(2, 2, (int (*)[2])buffer);

	return 0;
}