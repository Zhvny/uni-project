#include<stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	
	int N;
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		
		char S[N+1], K[N+1];
		scanf("%s", S);
		scanf("%s", K);
		
		int sum = 0;
		for	(int j = 0; j < N; j++){
			if (S[j] == K[j]){
				sum++;
			}
		}
		printf("Case #%d: %d\n", i + 1, sum * 100 / N ); 
	}
	return 0;
}
