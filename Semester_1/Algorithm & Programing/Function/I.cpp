#include <stdio.h>

int call_count = 0;
int fibonacci(int n) {
    call_count++;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);

        call_count = 0;
        
        int fib_value = fibonacci(n);
        
        printf("Case #%d: %d\n", i, call_count);
    }
    return 0;
}
