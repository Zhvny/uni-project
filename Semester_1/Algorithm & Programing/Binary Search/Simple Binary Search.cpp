#include <stdio.h>
#define SIZE 100

int binarySearch(int min, int max, int arr[], int dicari) {
    while (min <= max) {
        int mid = min + (max - min) / 2;
        if (arr[mid] < dicari) {
            min = mid + 1;
        } else if (arr[mid] > dicari) {
            max = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int arr[] = {11, 22, 33, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int angka;

    printf("Pilih angka 11, 22, 33, 44: ");
    scanf("%d", &angka);

    int hasil = binarySearch(0, n - 1, arr, angka);
    printf("\nAngka ada pada index: %d\n", hasil);
    return 0;
}

