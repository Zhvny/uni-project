#include<stdio.h>

int main(){
	double a, b;
	
	scanf("%lf %lf", &a, &b);
	
	double result = b / a * 100;
	
	printf("%.4lf%%\n", result);
	
	return 0;
}
