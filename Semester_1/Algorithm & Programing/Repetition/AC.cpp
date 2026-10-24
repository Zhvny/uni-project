#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        unsigned long long int M;
        unsigned long long int sum = 0;
        scanf("%d %llu", &N, &M);

        unsigned long long int min = 1000001;
        unsigned long long int A[N];

        for (int j = 0; j < N; j++) {
            scanf("%llu", &A[j]);
            if (A[j] < min) {
            	min = A[j];
			}
        }
		sum = M / min;
        printf("Case #%d: %llu\n", i + 1, sum);
    }
    return 0;
}


