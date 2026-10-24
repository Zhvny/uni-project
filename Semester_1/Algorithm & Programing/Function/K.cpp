#include <stdio.h>
#define SIZE 50

void fibbonaci(int f[SIZE], int k){
	for(int i = 0; i <= k; i++){
		f[i + 2] = f[i] + f[i + 1];
	}
}

int main(){
	int f[SIZE];
	int k;
	
	scanf("%d %d", &f[0], &f[1]);
	scanf("%d", &k);
	
	fibbonaci(f, k);
	
	printf("%d\n", f[k]);
	
	return 0;
}
