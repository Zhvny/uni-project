#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int A, B;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);

        int empty = A;
        int drunk = A;

        while (empty >= B) {
            int refill = empty / B;
            drunk += refill;
            empty = empty % B + refill;
        }
        printf("Case #%d: %d\n", i + 1, drunk);
    }
    return 0;
}
