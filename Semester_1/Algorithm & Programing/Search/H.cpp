#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void merge(long long arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    long long temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    long long Xi[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &Xi[i]);
    }
    
    long long Y;
    scanf("%lld", &Y);
    
    merge(Xi, 0, N - 1);
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (Y >= Xi[i]) {
            Y -= Xi[i];
            count++;
        } else {
            break;
        }
    }
    
    printf("%d\n", count);
    return 0;
}

