#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[1001] = {0};

    for (int i = 0; i < N; i++) {
        int item;
        scanf("%d", &item);
        A[item]++;
    }

    int max_frequency = 0;
    for (int i = 1; i <= 1000; i++) {
        if (A[i] > max_frequency) {
            max_frequency = A[i];
        }
    }

    printf("%d\n", max_frequency);

    return 0;
}

