#include <stdio.h>
#define SIZE 100

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int numbers[SIZE], to_remove[SIZE];

    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &to_remove[i]);
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (numbers[j] == to_remove[i]) {
                numbers[j] = -1;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < N; i++) {
        if (numbers[i] != -1 && numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    if (max == -1) {
        printf("Maximum number is -1\n");
    } else {
        printf("Maximum number is %d\n", max);
    }

    return 0;
}

