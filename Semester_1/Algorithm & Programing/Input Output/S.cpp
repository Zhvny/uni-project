#include<stdio.h>
#include<math.h>

int main(){
	double l, b, h;
	
	scanf("%lf %lf %lf", &l, &b, &h);

	//luas permukaan = alas x tinggi + 3(alas * lebar)
	printf("%.3lf\n", b * h + 3 * b * l);
	
	return 0;
}
