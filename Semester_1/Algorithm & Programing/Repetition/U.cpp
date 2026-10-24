#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int N;
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        char user;
        int B, L;
        int countB = 0, countL = 0;
        for (int j = 0; j <= N; j++) {
            scanf("%c", &user);

            if (user == 'B') {
                countB++;
            }

            else if (user == 'L') {
                countL++;
            }
            else if (user == 'T') {
                countB++;
                countL++;
            }
        }
        if (countB > countL) {
            printf("Bibi\n");
        }

        if (countB < countL) {
            printf("Lili\n");
        }

        if (countB == countL) {
            printf("None\n");
        }

    }
    return 0;
}

// 2 10 LBLBLBLBLB 5 LBLLL
