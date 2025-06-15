#include<stdio.h>
#include<math.h>

int main(){
	double X, Y;
	
	scanf("%lf %lf", &X, &Y);
	
	double a = Y / 100;
	double hasil = X * pow((1 + a), 3);
	
	printf("%.2lf\n", hasil);
	
	return 0;
}
