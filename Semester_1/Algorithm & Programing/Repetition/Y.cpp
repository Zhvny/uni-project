#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N, M;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &M);
        printf("Case #%d:\n", i + 1);

        for (int j = 0; j < M; j++) {
            printf("#");
        }
        printf("\n");

        for (int j = 0; j < N - 2; j++) {
            printf("#");
            for (int k = 0; k < M - 2; k++) {
                printf(" ");
            }
            printf("#\n");
        }
        if (N > 1){
        	for (int j = 0; j < M ; j++) {
            	printf("#");
        	}
       		printf("\n");
		}
    }
    return 0;
}
