//#define __COMPILE__
#ifdef __COMPILE__

#include <stdio.h>
#include "linalg.h"

#define printmatrix(mat, printel) printmat(mat, printel, DEFAULT_PRINTMAT_FORMAT)



void print_str(const char *);
void print_int(const void *);
void print_double(const void *);

const printmat_format_t DEFAULT_PRINTMAT_FORMAT = {
	print_str,
	"[", "\n ", "]\n",
	"[ ", ", ", " ]"
};



int main()
{
	matrix_t mat = init_mat(double, 3, 4, {
		{ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }
							});

	printmatrix(mat, print_double);
	putchar('\n');

	return 0;
}



void print_str(const char *str)
{
	printf("%s", str);
}

void print_int(const void *ptr)
{
	printf("%2d", *(const int *)ptr);
}

void print_double(const void *ptr)
{
	printf("%.2lf", *(const double *)ptr);
}

#endif
