#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	
	long long int N;
	for (int i = 0; i  < T; i++) {
		scanf("%lld", &N);
		
		int a = 1;
		int count = 0;
		while (N / a != 0){
			count++;
			a *= 10;
		}
		printf("%d\n", count);
	}
	return 0;
}
