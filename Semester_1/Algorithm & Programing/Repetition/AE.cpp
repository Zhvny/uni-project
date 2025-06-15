#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int R, H;
		scanf("%d %d", &R, &H);

		double hasil = 2 * 3.14 * R * (R + H);

		printf("Case #%d: %.2lf\n", i + 1, hasil);
	}
	return 0;
}


