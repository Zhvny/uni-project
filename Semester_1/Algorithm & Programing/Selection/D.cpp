#include<stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	long long int a, b;
	
for(int i = 1; i <= t; i++){
	scanf("%lld %lld", &a, &b);
	
	long long int katak0_0 = a * b;
	
		if(katak0_0 % 2 == 0){
			printf("Case #%d: Party time!\n", i);
		}
	
		else{
			printf("Case #%d: Need more frogs\n", i);
		}
	}

	return 0;
}
