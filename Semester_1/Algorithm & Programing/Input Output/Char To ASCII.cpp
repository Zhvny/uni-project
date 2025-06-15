#include<stdio.h>

int main(){
	char A, B;
	
	scanf("%c %c", &A, &B);
	
	int ascii1 = (int) A;
	int ascii2 = (int) B;	
	int C = A * B;
	
	printf("%d\n", C);
	
	return 0;
}
