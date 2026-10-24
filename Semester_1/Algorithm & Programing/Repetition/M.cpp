#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N, M;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &M);

        int X[i], sum = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &X[j]);

            sum += X[j];
        }
         printf("%d\n", sum);
        if (sum > M) {
            printf("Case #%d: Wash dishes\n", i + 1);
        }

        else if (sum <= M) {
            printf("Case #%d: No worries\n", i + 1);
        }
    }
    return 0;
}

// 2 5 10 1 2 3 4 5 3 100 6 8 2
