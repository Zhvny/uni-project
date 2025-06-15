#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N, K;
    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &N, &K);

        char S[N + 1];
        scanf("%s", S);

        for (int i = 0; i < N; i++) {
            int translate = S[i] - 'a';
            translate = (translate + K) % 26;
            S[i] = translate + 'a';
        }
        printf("Case #%d: %s\n", i, S);
    }
    return 0;
}
