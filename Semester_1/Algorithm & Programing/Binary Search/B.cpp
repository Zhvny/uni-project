#include <stdio.h>
#include <math.h>

long long sumSquare(long long N) {
    return N * (N + 1) * (2 * N + 1) / 6;
}

long long min(long long M) {
    long long left = 1, right = (long long)sqrt(2 * M), mid, result = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (sumSquare(mid) >= M) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        long long M;
        scanf("%lld", &M);
        long long N = min(M);
        printf("Case #%d: %lld\n", i, N);
    }

    return 0;
}

