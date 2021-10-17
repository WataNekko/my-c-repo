#include <stdio.h>

// This function stacks two 2d arrays vertically. And some other info...
void vstack(int m1, int m2, int n, int (*result)[n], int arr1[m1][n], int arr2[m2][n])
{
	int rows = m1 + m2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < n; j++) {
			if (i < m1) {
				result[i][j] = arr1[i][j];
			}
			else {
				result[i][j] = arr1[i - m1][j];
			}
		}
	}
}

// Some info about this function...
void flatten(int result[], int m, int n, int arr[m][n])
{
	int numel = m * n;
	for (int i = 0; i < numel; i++) {
		result[i] = arr[i / n][i % n];
	}
}

// This function actually just copies the whole memory of arr to result and do nothing
// else because n-d arrays in C (or arrays of arrays) are store contiguously in memory.
// (So does the other functions here actually :(( )
// And some other info about this function...
void reshape(int to_m, int to_n, int result[to_m][to_n],
			 int from_m, int from_n, int arr[from_m][from_n])
{

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