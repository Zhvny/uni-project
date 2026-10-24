#include <stdio.h>
#include <string.h>
#define MAX 10000

void fibonacciString(int n, const char* s0, const char* s1, char* result) {
    if (n == 0) {
        strcpy(result, s0); 
    } else if (n == 1) {
        strcpy(result, s1);
    } else {
        char s_n_minus_1[MAX];
        char s_n_minus_2[MAX];

        fibonacciString(n - 1, s0, s1, s_n_minus_1);
        fibonacciString(n - 2, s0, s1, s_n_minus_2);
        strcpy(result, s_n_minus_1);
        strcat(result, s_n_minus_2);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int n;
        char s0, s1;
        scanf("%d %c %c", &n, &s0, &s1);

        char str0[2] = {s0, '\0'};
        char str1[2] = {s1, '\0'};
        char result[MAX];
        
        fibonacciString(n, str0, str1, result);

        printf("Case #%d: %s\n", i, result);
    }

    return 0;
}
