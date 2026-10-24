#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

void countPrefixSum(int N, int A[], long long prefix[]) {
    prefix[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
}

int largestIndex(int N, long long prefix[], long long M) {
    int left = 0, right = N, mid, result = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (prefix[mid] <= M) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int N, Q;
    int A[SIZE];
    long long prefix[SIZE + 1];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    countPrefixSum(N, A, prefix);
    scanf("%d", &Q);

    for (int caseNum = 1; caseNum <= Q; caseNum++) {
        long long M;
        scanf("%lld", &M);
        int result = largestIndex(N, prefix, M);
        printf("Case #%d: %d\n", caseNum, result);
    }

    return 0;
}

