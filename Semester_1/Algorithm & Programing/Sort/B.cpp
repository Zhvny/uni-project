#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int R;
    char M[41];
} Plant;

void merge(Plant arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Plant L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].M, R[j].M) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Plant arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (!file) {
        printf("Error: file tidak dapat dibuka.\n");
        return 1;
    }

    int N;
    fscanf(file, "%d\n", &N);

    Plant plants[N];

    for (int i = 0; i < N; i++) {
        fscanf(file, "%d#%[^\n]\n", &plants[i].R, plants[i].M);
    }
    fclose(file);

    mergeSort(plants, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", plants[i].R, plants[i].M);
    }

    return 0;
}

