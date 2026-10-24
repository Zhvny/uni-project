#include<stdio.h>

int main(){
	double celcius, reamur, farenheit;
	
	scanf("%lf", &celcius);
	
	reamur = ( 4.0 / 5.0 * celcius);
	printf("%.1lf Reamur", reamur);
	
	farenheit =( 9.0 / 5.0 * celcius) + 32;
	printf("\n%.1lf Farenheit", farenheit);
	
	if( celcius > 40){
		printf("\nHot");
	}
	else if( 26 <= celcius && celcius <= 40){
		printf("\nCool");
	}
	else if( celcius < 26 ){
		printf("\nCold");
	}
	
	return 0;
}
