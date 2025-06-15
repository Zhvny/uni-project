#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long long int A[N];
    long long int sum = 0;

    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[N]);
        if(A[N] <= -1) {
            A[N] = 0;
        }
        sum += A[N];
    }
    printf("%lld\n", sum);
    return 0;
}
