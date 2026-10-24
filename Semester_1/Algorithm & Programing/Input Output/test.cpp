#include <stdio.h>

int main() {
    int A, B, C, D, hasil;
    int results[3];

    for (int i = 0; i < 3; ++i) {
        scanf("(%d+%d)x(%d-%d)", &A, &B, &C, &D);
        getchar();
        hasil = (A + B) * (C - D);
        results[i] = hasil;
    }

    for (int i = 0; i < 3; ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");

    return 0;
}

