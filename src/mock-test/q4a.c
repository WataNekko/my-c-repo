#include <stdio.h>
#include <stdlib.h>

void read_data(const char *file_name, float *area, float *price)
{
    FILE *file;
    char buffer[100];
    int i = 0;

    if ((file = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file \"%s\"", file_name);
        exit(1);
    }

    while (fgets(buffer, 100, file) != NULL) {
        sscanf(buffer, "%f,%f", &area[i], &price[i]);
        i++;
    }

    fclose(file);
}

int main()
{
    float area[4];
    float price[4];

    read_data("data.csv", area, price);
    for (int i = 0; i < 4; i++) {
        printf("area[%d]=%.1f\tprice[%d]=%.1f\n", i, area[i], i, price[i]);
    }

    return 0;
}