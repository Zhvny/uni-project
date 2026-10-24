#include <stdio.h>

int main() {
    long long A, B, C, D, hasil;
    long long results[3];

    for (int i = 0; i < 3; ++i) {
        scanf("(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D);
        getchar();
        hasil = (A + B) * (C - D);
        results[i] = hasil;
    }
	
	printf("%lld ", results[0]);
	printf("%lld ", results[1]);
	printf("%lld\n", results[2]);

    return 0;
}

