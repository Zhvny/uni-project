#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	int a1[T];

	int a;
	for (int t = 1; t <= T; t++) {
		scanf("%d", &a);
		a1[t-1] = a;
	}

	for (int t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);

		for (int u = 1; u <= a1[t-1]; u++){
			if (u%15 == 0) {
				printf("%d Lili\n", u);
			} else if (u%3 == 0 || u%5 == 0) {
				printf("%d Jojo\n", u);
			} else {
				printf("%d Lili\n", u);
			}
		}
	}
	return 0;
}	
