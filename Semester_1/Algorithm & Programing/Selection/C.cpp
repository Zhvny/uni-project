#include<stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int a, b;
	
for(int i = 1; i < t + 1; i++){
	scanf("%d %d", &a, &b);
	
		if(a > b){
			printf("Case #%d: Go-Jo\n", i);
		}
	
		else{
			printf("Case #%d: Bi-Pay\n", i);
		}
	}

	return 0;
}
