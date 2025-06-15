#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int weapons[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &weapons[i]);
    }

    int dragons[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &dragons[i]);
    }

    int maxDragons = 0;
    for (int i = 0; i < M; i++) {
        if (dragons[i] > maxDragons) {
            maxDragons = dragons[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (weapons[i] > maxDragons) {
            printf("The dark secret was true\n");
            return 0;
        }
    }
    printf("Secret debunked\n");
    return 0;
}
