#include <stdio.h>
#define size 10

void input(int angka[size]) {
    for (int i = 0; i < size; i++) {
        scanf("%d",&angka[i]);
    }
}

int getMin(int angka[size]) {
    int min = angka[0];
    for (int i = 0; i < size; i++) {
        if (angka[i] < min) {
            min = angka[i];
        }
    }
    return min;
}

int getMax(int angka[size]) {
    int max = angka[0];
    for (int i = 0; i < size; i++) {
        if (angka[i] > max) {
            max = angka[i];
        }
    }
    return max;
}

void display(int angka[size], int min, int max) {
    for (int i = 0; i < size; i++) {
        printf("%d ",angka[i]);
    }
    printf("\nMax = %d",max);
    printf("\nMin = %d\n",min);
}

int main() {
    int angka[size];
    input (angka);

    int min = getMin(angka);
    int max = getMax(angka);

    display (angka, min, max);

    return 0;
}
// 1 2 3 4 5 6 7 8 9 10
