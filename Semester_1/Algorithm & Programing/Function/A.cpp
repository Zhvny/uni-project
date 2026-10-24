#include <stdio.h>

int countMultiplesOf3 = 0;
int recursion(int n) {
    if (n == 0) {
        return 1;
    }

    else if (n == 1) {
        return 2;
    }

    else if (n % 5 == 0) {
        if (n % 3 == 0) {
            countMultiplesOf3++;
        }
        return n * 2;
    }

    else {
        if (n % 3 == 0) {
            countMultiplesOf3++;
        }
        return recursion(n - 1) + n + recursion(n - 2) + n - 2;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        countMultiplesOf3 = 0;

        int result = recursion(N);
        printf("Case #%d: %d %d\n", i + 1, result, countMultiplesOf3);
    }
    return 0;
}
// 7 2 3 4 5 6 14 15

