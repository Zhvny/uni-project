#include <stdio.h>

int F(int N) {
    if (N == 1) {
        return 1;
    } else if (N % 2 == 0) {
        return F(N / 2);
    } else {
        return F(N - 1) + F(N + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int result = F(N);

        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}
