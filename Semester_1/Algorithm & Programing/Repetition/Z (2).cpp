#include<stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	
	int K;
	int count = 0;
	for (int i = 0; i < N; i++){
		scanf("%d", &K);
		
		count += K;
		
		if (count == 30){
			count = 10;
		}
		else if (count == 12) {
			count = 28;
		}
		else if (count == 35) {
			count = 7;
		}
		else if (count >= 40){
			count = count % 40;
		}
	}
	printf("%d\n", count);
	return 0;
}
