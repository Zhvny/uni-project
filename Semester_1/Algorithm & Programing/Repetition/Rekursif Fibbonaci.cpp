#include <stdio.h>

int fib(int x){
	if(x <= 1){
		return x;
	}
	else {
		return fib(x - 1) + fib(x -2);
	}
}

int main(){
	int angka, hasil;
	printf("Input X untuk fibbonaci: ");
	scanf("%d", &angka);
	
	hasil = fib(angka);
	
	printf("\nHasil dari fibbonaci: %d\n", hasil);
	return 0;
}
