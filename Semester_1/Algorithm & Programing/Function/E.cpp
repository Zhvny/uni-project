#include <stdio.h>

int totalTrees(int A[], int N) {
    if (N <= 0) {
        return 0;
    }
    return A[N - 1] + totalTrees(A, N - 1);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        int result = totalTrees(A, N);

        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}
