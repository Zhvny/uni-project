#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == count + 1) {
            count++;
        }
        else {
            printf("%d ", count);
            count = 1;
        }
    }
    printf("%d\n", count);
    return 0;
}
