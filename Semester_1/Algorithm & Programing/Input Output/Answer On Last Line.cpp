#include <stdio.h>

int main() {
    int A, B, C, D, hasil;
    int results[2];

    for (int i = 0; i < 3; ++i) {
        scanf("(%d+%d)x(%d-%d)", &A, &B, &C, &D);
        getchar();
        hasil = (A + B) * (C - D);
        results[i] = hasil;
    }

        printf("%d ", results[0]);
        printf("%d ", results[1]);
        printf("%d\n", results[2]);
    

    return 0;
}

