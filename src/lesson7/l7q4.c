#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128

// a well-documented function...
int sum_num_string(const char *num_string)
{
	int sum = 0;
	char buffer[SIZE];			// copies string to a buffer to not overwrite
	strcpy(buffer, num_string); // the original string when splitting tokens.

	char *ptr = strtok(buffer, ", ");
	while (ptr != NULL) {
		sum += atoi(ptr); // converts the tokens to integers and adds to sum
		ptr = strtok(NULL, ", ");
	}

	return sum;
}

int main()
{
	char buffer[SIZE];

	printf("Input a comma-seperated list of integers:\n");
	fgets(buffer, SIZE, stdin);

	printf("\nSum = %d\n", sum_num_string(buffer));

	return 0;
}
