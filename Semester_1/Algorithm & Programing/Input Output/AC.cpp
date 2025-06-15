#include<stdio.h>
	
int main(){
	int A;
	
	scanf("%d", &A);
	
	long long int home_team = 1;
	for (int i = 0; i < A; i++){
		home_team *= 2;
	}
	
	long long int change_win = home_team - 1;
	
	printf("%lld\n", change_win);
	
	return 0;
}
