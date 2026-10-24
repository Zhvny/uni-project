#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);

        int Un[N];
        Un[0] = 1;

        for (int j = 1; j < N; j++) {
            Un[j] = Un[j - 1] + j;
        }

        printf("Case %d: ", i);
        for (int j = 0; j < N; j++) {
            printf("%d", Un[j]);
            if (j < N -1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
