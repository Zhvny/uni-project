#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int j, l, b;
    int count = 0;
    for (int j = 0; j <= N; j++) {
        for (int l = 0; l <= N - j; l++) {
            b = N - l - j;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
