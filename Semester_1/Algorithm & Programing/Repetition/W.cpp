#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);

		int odd = 0;
		int even = 0;

		for (int j = 0; j < N; j++) {
			int num;
			scanf("%d", &num);

			if (num % 2 == 0) {
				even++;
			} else {
				odd++;
			}
		}

		printf("Odd group : %d integer(s).\n", odd);
		printf("Even group : %d integer(s).\n\n", even);
	}
	return 0;
}


