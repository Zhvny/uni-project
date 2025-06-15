#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        long long int X; 
		int P;
        scanf("%lld %d", &X, &P);

        int bit = (X >> P) & 1;

        printf("%d\n", bit);
    }

    return 0;
}

