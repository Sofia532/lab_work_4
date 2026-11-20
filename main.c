#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main() {
    srand(time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int num_tests = 4;

    printf("| Размер |   Сортировка   | Время (в сек) | Количество перестановок |\n");
    for (int i = 0; i < num_tests; i++) {
        int size = sizes[i];

        int *icn = (int*)malloc(size * sizeof(int));
        int *arr_copy = (int*)malloc(size * sizeof(int));

        zapolnenye(icn, size);
        clock_t start, end;
        double seconds;
        long s;

        copy_array(icn, arr_copy, size);
        s = 0;
        start = clock();
        puzirkom(arr_copy, size, &s);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("| %6d | Пузырьком      | %15f | %30ld |\n", size, seconds, s);

        copy_array(icn, arr_copy, size);
        s = 0;
        start = clock();
        vstavkami(arr_copy, size, &s);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("| %6d | Вставками      | %15f | %30ld |\n", size, seconds, s);

        copy_array(icn, arr_copy, size);
        s = 0;
        start = clock();
        sliyaniem(arr_copy, 0, size - 1, &s);
        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("| %6d | Слиянием       | %15f | %30ld |\n", size, seconds, s);

        free(icn);
        free(arr_copy);
    }

    return 0;
}