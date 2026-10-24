#include <stdio.h>

long long maxSum(int A[], int N, long long M) {
    int start = 0, end = 0;
    long long sumNow = 0;
    int maxLength = -1;

    while (end < N) {
        sumNow += A[end];
        
        while (sumNow > M && start <= end) {
            sumNow -= A[start];
            start++;
        }
        
        if (sumNow <= M) {
            int length = end - start + 1;
            if (length > maxLength) {
                maxLength = length;
            }
        }
        
        end++;
    }

    return maxLength;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++) {
        long long M;
        scanf("%lld", &M);

        long long result = maxSum(A, N, M);

        printf("Case #%d: %lld\n", i, result);
    }

    return 0;
}

