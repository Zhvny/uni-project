#include<stdio.h>
	
int main(){
	int Click;
	
	scanf("%d", &Click);
	
	long long int TotalPoints = Click * 100.0 + 50.0 * (Click * (Click - 1.0)) / 2.0;
	
	printf("%lld\n", TotalPoints);
	
	return 0;
}
