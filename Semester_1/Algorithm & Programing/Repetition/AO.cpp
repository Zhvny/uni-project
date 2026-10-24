#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        getchar();

        char a[101];
        int aduh = 0;

        for (int j = 0; j < N; j++) {
            char ch = getchar();

            if (ch >= 'a' && ch <= 'z') {
                a[aduh] = ch;
                aduh++; // pindah lokasi penyimpanan array a[0] jadi a[1]
            }
        }
        a[aduh] = '\0'; // kealr array (null termiante)

        printf("Case #%d: %s\n", i, a);
    }

    return 0;
}

