#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_sample {
    int rooms;
    float area;
    float price;
};

void read_data(const char *file_name, struct data_sample *data)
{
    FILE *file;
    char buffer[100];
    int i = 0;

    if ((file = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file \"%s\"", file_name);
        exit(1);
    }

    while (fgetc(file) != '\n')
        ; // skip the first line

    while (fgets(buffer, 100, file) != NULL) {
        if (strlen(buffer) <= 1) {
            continue; // skip if is blank line
        }
        sscanf(buffer, "%d,%f,%f", &data[i].rooms, &data[i].area, &data[i].price);
        i++;
    }

    fclose(file);
}

void print_data(struct data_sample *data_array, int length)
{
    for (int i = 0; i < length; i++) {
        printf("data[%d]: rooms=%d\tarea=%.1f\tprice=%.1f\n", i, data_array[i].rooms, data_array[i].area, data_array[i].price);
    }
}

int main()
{
    struct data_sample data_array[6];

    read_data("data1.csv", data_array);
    print_data(data_array, 6);

    return 0;
}
