#include <stdio.h>
#include <string.h>

void reverseString(char *str, int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++) {
        char S[1001];
        fgets(S, sizeof(S), stdin);
        S[strcspn(S, "\n")] = 0; 
        reverseString(S, 0, strlen(S) - 1);

        printf("Case #%d: %s\n", i, S);
    }

    return 0;
}
