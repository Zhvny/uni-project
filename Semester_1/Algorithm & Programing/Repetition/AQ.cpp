#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    char S[101];
    for (int i = 0; i < T; i++) {
        scanf("%s", S);

        int dot = 0;
        int num = 0;
        int valid = 1;

        for (int j = 0; S[j] != '\0'; j++) {
            if (S[j] == '.') {
                dot++;

                if (num == 0) {
                    valid = 0;
                    break;
                }
                num = 0;
            }

            else if (S[j] >= '0' && S[j] <= '9') {
                num++;
            }

            else {
                valid = 0;
                break;
            }
        }

        if (num == 0) {
            valid = 0;
        }

        if(dot != 5) {
            valid = 0;
        }

        if (valid) {
            printf("Case #%d: YES\n", i + 1);
        }
        else {
            printf("Case #%d: NO\n", i + 1);
        }
    }
    return 0;
}

