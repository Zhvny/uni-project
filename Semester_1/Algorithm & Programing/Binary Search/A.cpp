#include <stdio.h>
#define SIZE 100000

int temp[SIZE] = {0};

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return (result == -1) ? -1 : result + 1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[SIZE], Q[SIZE];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, N - 1);

    for (int i = 0; i < M; i++) {
        scanf("%d", &Q[i]);
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", binarySearch(A, N, Q[i]));
    }

    return 0;
}

