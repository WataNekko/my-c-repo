#include <stdio.h>

// Matrix multiplication doc...
void matmult(int m, int n, int p, int result[m][p], int mat1[m][n], int mat2[n][p])
{
	// iterates through each column of result
	for (int k = 0; k < p; k++) {
		for (int i = 0; i < m; i++) {
			// sums the products and stores in a result entry
			result[i][k] = 0;
			for (int j = 0; j < n; j++) {
				result[i][k] += mat1[i][j] * mat2[j][k];
			}
		}
	}
}

// doc
void matvecmult(int m, int n, int result[], int mat[m][n], int vec[])
{
	// We can consider vectors as matrices with only one row or one column. Therefore,
	// vector-matrix multiplication are the same as matrix-matrix multiplication and we
	// can pass the arguments to matmult as follows:
	matmult(m, n, 1, (int (*)[1])result, mat, (int (*)[1])vec);
}

//doc
void vecmatmult(int m, int n, int result[], int vec[], int mat[m][n])
{
	// We can consider vectors as matrices with only one row or one column. Therefore,
	// vector-matrix multiplication are the same as matrix-matrix multiplication and we
	// can pass the arguments to matmult as follows:
	matmult(1, m, n, (int (*)[n])result, (int (*)[m])vec, mat);
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
	// Vector-matrix multiplication
	{
		int mat[2][2] = { { 1, 2 }, { 3, 4 } };
		int vec[2] = { 1, 2 };
		int result[2];

		// mat-vec
		matvecmult(2, 2, result, mat, vec);

		printf("mat =\n");
		disp(2, 2, mat);
		printf("vec = \n");
		disp(2, 1, (int (*)[1])vec);
		printf("mat x vec =\n");
		disp(2, 1, (int (*)[1])result);
		putchar('\n');

		// vec-mat
		vecmatmult(2, 2, result, vec, mat);

		printf("vec = "); disp(1, 2, (int (*)[2])vec);
		printf("mat =\n");
		disp(2, 2, mat);
		printf("vec x mat = "); disp(1, 2, (int (*)[2])result);
		putchar('\n');
	}

	// Matrix-matrix multiplication
	{
		int mat1[2][2] = { { 1, 2 }, { 3, 4 } };
		int mat2[2][2] = { { 2, 3 }, { 2, 1 } };
		int result[2][2];

		matmult(2, 2, 2, result, mat1, mat2);

		printf("mat1 =\n");
		disp(2, 2, mat1);
		printf("mat2 =\n");
		disp(2, 2, mat2);
		printf("mat1 x mat2 =\n");
		disp(2, 2, result);

		matmult(2, 2, 2, result, mat2, mat1);

		printf("mat2 x mat1 =\n");
		disp(2, 2, result);
	}

	return 0;
}