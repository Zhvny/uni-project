#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int N, i, maxDiff = 0;

    scanf("%d", &N);

    int A[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, N - 1);

    for (i = 1; i < N; i++) {
        int diff = A[i] - A[i - 1];
        if (diff > maxDiff) {
            maxDiff = diff;
        }
    }

    int first = 1;
    for (i = 1; i < N; i++) {
        if (A[i] - A[i - 1] == maxDiff) {
            if (!first) printf(" ");
            printf("%d %d", A[i - 1], A[i]);
            first = 0;
        }
    }

    printf("\n");
    return 0;
}

