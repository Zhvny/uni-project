#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int left = 0, max_length = -1;
        long long current_sum = 0;

        for (int right = 0; right < N; right++) {
            current_sum += A[right];

            while (current_sum > M) {
                current_sum -= A[left];
                left++;
            }

            int current_length = right - left + 1;
            if (current_length > max_length) {
                max_length = current_length;
            }
        }

        printf("Case #%d: %d\n", t, max_length);
    }

    return 0;
}

