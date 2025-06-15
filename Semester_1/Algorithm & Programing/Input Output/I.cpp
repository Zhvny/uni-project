#include<stdio.h>

int main(){
	int a;
	
	scanf("%d", &a);
	
	int b = a + a;
	int c = b - 1;
	
	printf("%d plus %d is %d\nminus one is %d\n", a, a , b, c);
	
	return 0;
}
