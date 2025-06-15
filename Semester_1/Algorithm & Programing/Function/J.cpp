#include <stdio.h>

const char* detWinner(int n) {
    int turn = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        turn = 1 - turn;
    }
    return (turn == 1) ? "Jojo" : "Lili";
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        const char* winner = detWinner(N);
        printf("Case #%d: %s\n", i, winner);
    }
    return 0;
}
