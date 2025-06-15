#include<stdio.h>

int main(){
	double X, Y;
	
	scanf("%lf %lf", &X, &Y);
	
	double hasil = 100 - Y / X * 100;
	
	printf("%.2lf%%\n", hasil);
	
	return 0;
}
