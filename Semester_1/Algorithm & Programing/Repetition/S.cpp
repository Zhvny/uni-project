#include <stdio.h>

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    int A[N], count = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);

        if (A[i] < P) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

// 10 8 1 2 3 4 5 6 7 8 9 10
