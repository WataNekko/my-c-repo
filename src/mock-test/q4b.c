#include <stdio.h>
#include <stdlib.h>

struct house_info {
    float area;
    float price;
};

void read_data(const char *file_name, struct house_info *house)
{
    FILE *file;
    char buffer[100];
    int i = 0;

    if ((file = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file \"%s\"", file_name);
        exit(1);
    }

    while (fgets(buffer, 100, file) != NULL) {
        sscanf(buffer, "%f,%f", &house[i].area, &house[i].price);
        i++;
    }

    fclose(file);
}

int main()
{
    struct house_info house[4];

    read_data("data.csv", house);
    for (int i = 0; i < 4; i++) {
        printf("house[%d].area=%.1f\thouse[%d].price=%.1f\n", i, house[i].area, i, house[i].price);
    }

    return 0;
}