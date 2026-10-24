#include<stdio.h>

int main(){
	double x, y;
	
	for (int i = 0; i < 4; i++) {
	scanf("%lf %lf", &x, &y);

	double hasil = y / (1 - x / 100.0);
	
	printf("$%.2lf\n", hasil);
}

	return 0;
}
