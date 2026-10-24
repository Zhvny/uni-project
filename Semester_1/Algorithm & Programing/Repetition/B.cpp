#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int count = N;
    for (int i = 1; i <= M; i++) {
        printf("%d\n", count);
        count++;
    }
    return 0;
}

