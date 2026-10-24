#include<stdio.h>

int main(){
	
	double ipk;
	
	printf("IPK Input:");
	getchar();
	scanf("%lf", &ipk);
	
	if(3.5 <= ipk && ipk <= 4.0){
		printf("Cumlaude\n");
	}
	else if(3.0 <= ipk && ipk <= 3.5){
		printf("Outstanding\n");
	}
	else if(2.5 <= ipk && ipk <= 3.0){
		printf("Very Good\n");
	}
	else if(2.0 <= ipk && ipk <= 2.5){
		printf("Good\n");
	}
	else if(ipk < 2.0){
		printf("Poor\n");
	}
	
	return 0;
}
