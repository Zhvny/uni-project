#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++) {
        char str[1001];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;
        int len = strlen(str);
        int result = isPalindrome(str, 0, len - 1);

        if (result) {
            printf("Case #%d: yes\n", i);
        } else {
            printf("Case #%d: no\n", i);
        }
    }

    return 0;
}
