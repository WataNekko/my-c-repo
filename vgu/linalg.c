#define __COMPILE__
#ifdef __COMPILE__

#include "linalg.h"
#include <stdlib.h>
#include <string.h>



const matrix_t EMPTY_MATRIX = { 0, 0, 0, NULL };



/// <summary>
/// Dynamically allocates a matrix object and returns a matrix_t object representing it.
/// </summary>
/// <param name="num_of_rows">-The number of rows of the matrix to be allocated.</param>
/// <param name="num_of_columns">-The number of columns of the matrix to be allocated.</param>
/// <param name="element_size">-The size of each element of the matrix to be allocated.</param>
/// <returns>A matrix_t object representing the allocated matrix.</returns>
matrix_t allocmat(size_t num_of_rows, size_t num_of_columns, size_t element_size)
{
	matrix_t mat = EMPTY_MATRIX;
	size_t matsize = num_of_rows * num_of_columns * element_size;

	if ((matsize > 0) && ((mat.base = malloc(matsize)) != NULL)) {
		mat.num_of_rows = num_of_rows;
		mat.num_of_columns = num_of_columns;
		mat.element_size = element_size;
	}

	return mat;
}

/// <summary>
/// Deallocates a dynamically allocated matrix object.
/// </summary>
/// <param name="mat">-A pointer to the matrix_t object to be deallocate.</param>
void freemat(matrix_t *mat)
{
	free(mat->base);
	*mat = EMPTY_MATRIX;
}

/// <summary>
/// Prints a matrix with the given print function and format.
/// </summary>
/// <param name="mat">-The matrix to be printed.</param>
/// <param name="print_element">-The print function to use on each element of the matrix.</param>
/// <param name="format">-The printmat format to use.</param>
void printmat(matrix_t mat, void (*print_element)(const void *), printmat_format_t format)
{
	char *ptr = mat.base;

	//========== left enclosing row delimiter ==========//
	format.print_delimiter(format.left_row_delimiter);

	for (size_t row = 0; row < mat.num_of_rows; row++) {
		//----- left enclosing column delimiter -----//
		format.print_delimiter(format.left_column_delimiter);

		for (size_t col = 0; col < mat.num_of_columns; col++) {
			print_element(ptr); // prints the elements

			if (col < mat.num_of_columns - 1) {
				//// column elements delimiter ////
				format.print_delimiter(format.column_delimiter);
			}

			ptr += mat.element_size; // increments ptr to the next element
		}

		format.print_delimiter(format.right_column_delimiter);
		//----- right enclosing column delimiter -----//

		if (row < mat.num_of_rows - 1) {
			//// rows delimiter ////
			format.print_delimiter(format.row_delimiter);
		}
	}

	format.print_delimiter(format.right_row_delimiter);
	//========== right enclosing row delimiter ==========//
}

/// <summary>
/// Gets the number of elements of a matrix.
/// </summary>
/// <param name="mat">-The matrix whose number of elements is to be returned.</param>
/// <returns>The number of elements of the matrix.</returns>
size_t numel(matrix_t mat)
{
	return mat.num_of_rows * mat.num_of_columns;
}

/// <summary>
/// Gets a pointer to the element of the matrix with the given row and column indices. This function does no bound check.
/// </summary>
/// <param name="mat">-The matrix from which to get the element.</param>
/// <param name="row">-The zero-based row index of the element.</param>
/// <param name="col">-The zero-based column index of the element.</param>
/// <returns>A pointer to the element of the matrix with the given indices.</returns>
void *mat_get_element(matrix_t mat, size_t row, size_t col)
{
	return (char *)mat.base + (row * mat.num_of_columns + col) * mat.element_size;
}

/// <summary>
/// Gets a pointer to the beginning of a row of a matrix.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="row">-The zero-based row index.</param>
/// <returns>A pointer to the beginning of the row.</returns>
void *mgetrow(matrix_t mat, size_t row)
{
	return mat_get_element(mat, row, 0);
}

/// <summary>
/// Swaps the content of two vectors using an additional temporary buffer.
/// </summary>
/// <param name="a">-The first vector argument.</param>
/// <param name="b">-The second vector argument.</param>
/// <param name="temp">-The temporary buffer to be used for swapping.</param>
/// <param name="size">-The size in bytes of the vector arguments.</param>
void vec_swap(void *a, void *b, void *temp, const size_t size)
{
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
}

/// <summary>
/// Interchanges two rows of a matrix using an additional temporary buffer.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="row_a">-The index of the row to be interchanged with row_b.</param>
/// <param name="row_b">-The index of the row to be interchanged with row_a.</param>
/// <param name="temp">-The temporary buffer to be used for swapping.</param>
void row_swap(matrix_t mat, size_t row_a, size_t row_b, void *temp)
{
	void *a = mat_get_element(mat, row_a, 0);
	void *b = mat_get_element(mat, row_b, 0);
	vec_swap(a, b, temp, mat.num_of_columns * mat.element_size);
}

static void _vec_op(size_t length, size_t element_size, void (*operation)(const size_t, void *, va_list), void *vec_base, va_list args)
{
	size_t vecsize = length * element_size;

	for (size_t offset = 0; offset < vecsize; offset += element_size) {
		operation(offset, vec_base, args);
	}
}

/// <summary>
/// Performs an element-wise operation on the given vector.
/// </summary>
/// <param name="length">-The length of the vector.</param>
/// <param name="element_size">-The size of an element of the vector.</param>
/// <param name="operation">-The operation to perform on each element of the vector. This is a pointer to a function that returns void and accepts a size_t argument as the offset of the element from the base, a void pointer argument as the base of the vector and a va_list as the variable argument list.</param>
/// <param name="vec_base">-The base of the vector to pass into the operation function.</param>
void vec_op(size_t length, size_t element_size, void (*operation)(const size_t, void *, va_list), void *vec_base, ...)
{
	va_list args;
	va_start(args, vec_base);
	_vec_op(length, element_size, operation, vec_base, args);
	va_end(args);
}

/// <summary>
/// Performs a row operation on the matrix.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="operation">-The row operation to perform.</param>
/// <param name="rowptr">-The pointer to the row on which to perform the operation.</param>
void row_op(matrix_t mat, void (*operation)(const size_t, void *, va_list), void *rowptr, ...)
{
	va_list args;
	va_start(args, rowptr);
	_vec_op(mat.num_of_columns, mat.element_size, operation, rowptr, args);
	va_end(args);
}

/// <summary>
/// Performs a scaling operation on double type. The arguments passed need to be as follow:
/// The offset from the base, the source base from which to read the value, the destination base into which to store the result, the scalar by which to scale the source value.
/// </summary>
void op_scale(const size_t offset, void *vec_base, va_list args)
{
	double *src = (double *)((char *)vec_base + offset);
	double *dest = (double *)(va_arg(args, char *) + offset);
	double scalar = va_arg(args, double);
	*dest = *src * scalar;
}

/// <summary>
/// Performs an addition operation on double type. The arguments passed need to be as follow:
/// The offset from the base, the first source base from which to read the value, the second source base from which to read the value, the destination base into which to store the result of the addition of the two source values.
/// </summary>
void op_add(const size_t offset, void *vec_base, va_list args)
{
	double *src_a = (double *)((char *)vec_base + offset);
	double *src_b = (double *)(va_arg(args, char *) + offset);
	double *dest = (double *)(va_arg(args, char *) + offset);
	*dest = *src_a + *src_b;
}

#endif
