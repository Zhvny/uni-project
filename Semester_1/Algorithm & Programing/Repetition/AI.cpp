#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N;
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        int A[N];
        long long total = 0;

        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
            total += A[j];
        }

        long long ltotal = 0;
        int bisa_dibagi_2_kelompok = 0;

        for (int j = 0; j < N - 1; j++) {
            ltotal += A[j];
            total -= A[j];

            if (ltotal == total) {
                bisa_dibagi_2_kelompok = 1;
                break;
            }
        }
            if (bisa_dibagi_2_kelompok) {
                printf("Case #%d: Yes\n", i + 1);
            }
            else {
                printf("Case #%d: No\n", i + 1);
            }
    }
    return 0;
}
