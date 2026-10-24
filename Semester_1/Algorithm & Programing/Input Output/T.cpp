#include<stdio.h>

int main(){
	int h1, m1, h2, m2, m3;
	char cc[20];

	for(int i=0; i<5; i++){
		scanf("%s %d:%d-%d:%d", cc, &h1, &m1, &h2, &m2);
		getchar();
		printf("%s %02d:%02d-%02d:%02d\n", cc, h1-1, m1, h2-1, m2);
	}
	return 0;
}
