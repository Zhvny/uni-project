#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        long long total = 0;

        for (int i = 0; i < N; i++) {
            int item;
            scanf("%d", &item);
            total += item;
        }

        printf("Case #%d: %lld\n", t, total);
    }

    return 0;
}

