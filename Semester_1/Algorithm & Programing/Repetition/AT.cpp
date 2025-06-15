#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int X;
    for (int i = 0; i < T; i++) {
        scanf("%d", &X);

        for (int j = 1; j <= X; j++) {
            for (int k = 0; k < X - j ; k++) {
                printf(" ");
            }
            for (int k = 0; k < 2 * j -1; k++) {
                printf("*");
            }
            printf("\n");
        }
        // // if (i < T - 1) {
        // //     printf("\n");
        // }
    }
    return 0;
}
