#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int position = 0;

    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        position += K;

        if (position == 30) {
            position = 10;
        }

        else if (position == 12) {
            position = 28;
        }

        else if (position == 35) {
            position = 7;
        }
    }
    printf("%d\n", position);
    return 0;
}

