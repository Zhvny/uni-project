#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N;
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        if (N == 1){
            printf("*\n");
            if (T > 0) {
                printf("\n");
            }
            continue;
        }

        for (int i = 0; i < N; i++) {
            printf("*");
        }
        printf("\n");

        for (int i = 1; i < N - 1; i++) {
            printf("*");

            for (int j = 1; j < N - 1; j++) {
                if (i == j || i + j == N - 1) {
                    printf("*");
                }

                else {
                    printf(" ");
                }
            }
            printf("*\n");
        }
        for (int i = 0; i < N; i++) {
            printf("*");
        }
        printf("\n");

        if (T > 0) {
            printf("\n");
        }
    }
    return 0;
}
