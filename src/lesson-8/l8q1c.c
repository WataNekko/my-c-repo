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
				result[i][j] = arr2[i - m1][j];
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
// else because n-d arrays in C (or arrays of arrays) are stored contiguously in memory.
// We are just changing the metadata, i.e., the info about the size of the 2d arrays.
// (So does the other functions in here actually :(( )
// 
// And some other info about this function...
void reshape(int old_m, int old_n, int arr[old_m][old_n],
			 int new_m, int new_n, int result[new_m][new_n])
{
	if (old_m * old_n != new_m * new_n) {
		printf("Error: inconsistent dimension inputs.");
		return;
	}

	int old_i = 0;
	int old_j = 0;
	// iterates through the result array with the new size
	for (int new_i = 0; new_i < new_m; new_i++) {
		for (int new_j = 0; new_j < new_n; new_j++) {
			result[new_i][new_j] = arr[old_i][old_j]; // copies data over

			// keeps track of and increments the old indices accordingly
			if (++old_j >= old_n) {
				old_i++;
				old_j = 0;
			}
		}
	}
}

// Compares the array to 'num' and produces a boolean mask on whether each element is
// greater than 'num'.
// 
// >> insert some more info...
void compare_gt(int m, int n, int arr[m][n], int result_mask[m][n], int num)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			result_mask[i][j] = (arr[i][j] > num);
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
	// vstack
	{
		int arr_1[1][3] = { { 1, 2, 3 } };
		int arr_2[1][3] = { { 4, 5, 6 } };
		int result[2][3];

		vstack(1, 1, 3, result, arr_1, arr_2);

		printf("arr_1 = "); disp(1, 3, arr_1);
		printf("arr_2 = "); disp(1, 3, arr_2);
		printf("vstack(arr_1, arr_2) =\n");
		disp(2, 3, result);
	}
	putchar('\n');

	// flatten
	{
		int data[2][3] = { { 4, 2, 4 }, { 2, 2, 1 } };
		int result[6];

		flatten(result, 2, 3, data);

		printf("data =\n");
		disp(2, 3, data);
		printf("flatten(data) = "); disp(1, 6, (int (*)[6])result);
	}
	putchar('\n');

	// reshape
	{
		int data[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
		int data_rs[3][2];

		reshape(2, 3, data, 3, 2, data_rs);

		printf("data =\n");
		disp(2, 3, data);
		printf("reshape(data, 3, 2) =\n");
		disp(3, 2, data_rs);
	}
	putchar('\n');

	// compare
	{
		int arr[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
		int mask[3][2];

		compare_gt(3, 2, arr, mask, 2);

		printf("arr =\n");
		disp(3, 2, arr);
		printf("arr > 2 =\n");
		disp(3, 2, mask);
	}

	return 0;
}