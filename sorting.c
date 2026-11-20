#include <stdlib.h>
#include "sorting.h"

void zapolnenye(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

void copy_array(int *source, int *to, int size) {
    for (int i = 0; i < size; i++) {
        to[i] = source[i];
    }
}

void puzirkom(int *arr, int size, long *k) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                (*k)++;
            }
        }
    }
}

void vstavkami(int *arr, int size, long *k) {
    for (int i = 1; i < size; i++) {
        int e = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > e) {
            arr[j + 1] = arr[j];
             j = j - 1;
             (*k)++;
            }
            arr[j + 1] = e;
        }
}

void sliyaniem(int *arr, int left, int right, long *k) {
    if (left >= right) return;
    int mid = (left + right)  / 2;
    sliyaniem(arr, left, mid, k);
    sliyaniem(arr, mid + 1, right, k);
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, idx = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[idx] = L[i];
            i++;
        } else {
            arr[idx] = R[j];
            j++;
            (*k)++;
        }
        idx++;
    }

    while (i < n1) {
        arr[idx] = L[i];
        i++;
        idx++;
    }
     while (j < n2) {
        arr[idx] = R[j];
        j++;
        idx++;
    }

    free(L);
    free(R);
}