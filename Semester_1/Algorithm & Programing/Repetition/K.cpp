#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        printf("Case #%d:\n", i + 1);

        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N - j; k++) {
                printf(" ");
            }

            for (int k = 1; k <= j; k++) {
                if (N == 1) {
                    printf("*");
                    break;
                }

                else if (N % 2 == 0) {
                    if (j % 2 == 0) {
                        if (k % 2 == 0) {
                            printf("*");
                        }

                        else if (k % 2 == 1) {
                            printf("#");
                        }
                    }

                    else if (j % 2 == 1) {
                        if (k % 2 == 0) {
                            printf("*");
                        }

                        else if (k % 2 == 1) {
                            printf("#");
                        }
                    }
                }

                else if (N % 2 == 1) {
                    if (j % 2 == 0) {
                        if (k % 2 == 0) {
                            printf("#");
                        }

                        else if (k % 2 == 1) {
                            printf("*");
                        }
                    }

                    else if (j % 2 == 1) {
                        if (k % 2 == 0) {
                            printf("#");
                        }

                        else if (k % 2 == 1) {
                            printf("*");
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
