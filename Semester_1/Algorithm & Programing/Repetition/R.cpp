#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N;
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        int X[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &X[j]);
        }

        int min = X[1] - X[0];
        if (min < 0) {
            min = -min;
        }

        int dif;
        for (int j = 0; j < N - 1; j++) {
            dif = X[j + 1] - X[j];
            if (dif < 0) {
                dif = -dif;
            }

            if (dif <= min) {
                min = dif;
            }
        }
        printf("Case #%d: %d\n", i + 1, min);
    }
    return 0;
}

// 3 4 1 2 3 4 5 10 2 4 1 5 2 1 10
