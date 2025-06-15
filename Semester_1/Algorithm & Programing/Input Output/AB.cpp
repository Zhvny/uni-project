#include<stdio.h>
	
int main(){
	int Hit;
	
	scanf("%d", &Hit);
	
	long long int TotalDamage = Hit * 100.0 + 50.0 * (Hit * (Hit - 1.0)) / 2.0;
	
	printf("%lld\n", TotalDamage);
	
	return 0;
}
