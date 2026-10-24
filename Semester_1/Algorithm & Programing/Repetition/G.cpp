#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int each_cage, sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &each_cage);

        sum += each_cage;
    }
    printf("%d\n", sum);
    return 0;
}
