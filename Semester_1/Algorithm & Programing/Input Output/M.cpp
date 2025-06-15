#include<stdio.h>

int main(){
	double X, Y;
	
	scanf("%lf %lf", &X, &Y);
	
	double hasil = X / Y * 100;
	
	printf("%.2lf%%\n", hasil);
	
	return 0;
}
