#pragma once

#include <stddef.h>
#include <stdarg.h>



// This macro provides a quick way to initialize a matrix_t variable.
#define init_mat(type, num_row, num_col, ...) { num_row, num_col, sizeof(type), &(type[num_row][num_col])__VA_ARGS__ }

// Gets the lvalue of an element in mat.
#define mat_el(type, mat, row, col) (*(type *)mat_get_element(mat, row, col))



/// <summary>
/// Represents a matrix object.
/// </summary>
typedef struct matrix_t {
	size_t num_of_rows;
	size_t num_of_columns;
	size_t element_size;
	void *base;
} matrix_t;

extern const matrix_t EMPTY_MATRIX;

/// <summary>
/// Stores the format to be used in the printmat function.
/// </summary>
typedef struct printmat_format_t {
	void (*print_delimiter)(const char *);
	char *left_row_delimiter;
	char *row_delimiter;
	char *right_row_delimiter;
	char *left_column_delimiter;
	char *column_delimiter;
	char *right_column_delimiter;
} printmat_format_t;



/// <summary>
/// Dynamically allocates a matrix object and returns a matrix_t object representing it.
/// </summary>
/// <param name="num_of_rows">-The number of rows of the matrix to be allocated.</param>
/// <param name="num_of_columns">-The number of columns of the matrix to be allocated.</param>
/// <param name="element_size">-The size of each element of the matrix to be allocated.</param>
/// <returns>A matrix_t object representing the allocated matrix.</returns>
matrix_t allocmat(size_t num_of_rows, size_t num_of_columns, size_t element_size);
/// <summary>
/// Deallocates a dynamically allocated matrix object.
/// </summary>
/// <param name="mat">-A pointer to the matrix_t object to be deallocate.</param>
void freemat(matrix_t *mat);

/// <summary>
/// Prints a matrix with the given print function and format.
/// </summary>
/// <param name="mat">-The matrix to be printed.</param>
/// <param name="print_element">-The print function to use on each element of the matrix.</param>
/// <param name="format">-The printmat format to use.</param>
void printmat(matrix_t mat, void (*print_element)(const void *), printmat_format_t format);

/// <summary>
/// Gets the number of elements of a matrix.
/// </summary>
/// <param name="mat">-The matrix whose number of elements is to be returned.</param>
/// <returns>The number of elements of the matrix.</returns>
size_t numel(matrix_t mat);
/// <summary>
/// Gets a pointer to the element of the matrix with the given row and column indices. This function does no bound check.
/// </summary>
/// <param name="mat">-The matrix from which to get the element.</param>
/// <param name="row">-The zero-based row index of the element.</param>
/// <param name="col">-The zero-based column index of the element.</param>
/// <returns>A pointer to the element of the matrix with the given indices.</returns>
void *mat_get_element(matrix_t mat, size_t row, size_t col);
/// <summary>
/// Gets a pointer to the beginning of a row of a matrix.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="row">-The zero-based row index.</param>
/// <returns>A pointer to the beginning of the row.</returns>
void *mgetrow(matrix_t mat, size_t row);

/// <summary>
/// Swaps the content of two vectors using an additional temporary buffer.
/// </summary>
/// <param name="a">-The first vector argument.</param>
/// <param name="b">-The second vector argument.</param>
/// <param name="temp">-The temporary buffer to be used for swapping.</param>
/// <param name="size">-The size in bytes of the vector arguments.</param>
void vec_swap(void *a, void *b, void *temp, const size_t size);
/// <summary>
/// Interchanges two rows of a matrix using an additional temporary buffer.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="row_a">-The index of the row to be interchanged with row_b.</param>
/// <param name="row_b">-The index of the row to be interchanged with row_a.</param>
/// <param name="temp">-The temporary buffer to be used for swapping.</param>
void row_swap(matrix_t mat, size_t row_a, size_t row_b, void *temp);
/// <summary>
/// Performs an element-wise operation on the given vector.
/// </summary>
/// <param name="length">-The length of the vector.</param>
/// <param name="element_size">-The size of an element of the vector.</param>
/// <param name="operation">-The operation to perform on each element of the vector. This is a pointer to a function that returns void and accepts a size_t argument as the offset of the element from the base, a void pointer argument as the base of the vector and a va_list as the variable argument list.</param>
/// <param name="vec_base">-The base of the vector to pass into the operation function.</param>
void vec_op(size_t length, size_t element_size, void (*operation)(const size_t, void *, va_list), void *vec_base, ...);
/// <summary>
/// Performs a row operation on the matrix.
/// </summary>
/// <param name="mat">-The input matrix.</param>
/// <param name="operation">-The row operation to perform.</param>
/// <param name="rowptr">-The pointer to the row on which to perform the operation.</param>
void row_op(matrix_t mat, void (*operation)(const size_t, void *, va_list), void *rowptr, ...);
/// <summary>
/// Performs a scaling operation on double type. The arguments passed need to be as follow:
/// The offset from the base, the source base from which to read the value, the destination base into which to store the result, the scalar by which to scale the source value.
/// </summary>
void op_scale(const size_t offset, void *vec_base, va_list args);
/// <summary>
/// Performs an addition operation on double type. The arguments passed need to be as follow:
/// The offset from the base, the first source base from which to read the value, the second source base from which to read the value, the destination base into which to store the result of the addition of the two source values.
/// </summary>
void op_add(const size_t offset, void *vec_base, va_list args);
