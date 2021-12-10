#include <stdio.h>
#include <string.h>

void q5_function(char *str1, char *str2)
{
    int length = strlen(str1);
    for (int i = 0; i < length; i += 2) {
        // swap even index characters
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }

    // concatenate the second string to the first string
    strcat(str1, str2);
}

int main()
{
    // test case 1
    {
        printf("Example 1:\n");

        char str1[50] = "abcd1";
        char str2[] = "efgh2";

        // print input
        printf("input:\n");
        printf("  str1 = \"%s\"\n", str1);
        printf("  str2 = \"%s\"\n", str2);

        // result
        q5_function(str1, str2);

        printf("result:\n");
        printf("  str1 = \"%s\"\n", str1);
        printf("  str2 = \"%s\"\n", str2);
    }

    // test case 2
    {
        printf("\nExample 2:\n");

        char str1[50] = "12345678";
        char str2[] = "87654321";

        // print input
        printf("input:\n");
        printf("  str1 = \"%s\"\n", str1);
        printf("  str2 = \"%s\"\n", str2);

        // result
        q5_function(str1, str2);

        printf("result:\n");
        printf("  str1 = \"%s\"\n", str1);
        printf("  str2 = \"%s\"\n", str2);
    }

    return 0;
}
