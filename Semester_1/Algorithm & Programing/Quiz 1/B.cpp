#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d%*c", &N, &M);
	
		string a[201];
		for (int i = 0; i < N; i++){
			scanf("%s", &a);
		}	
	
		int X = 0;
		for (int i = 0; i < M; i++){
			scanf("%d", &X);
			
			if (a >= 'a' && a <= 'z'){
				printf("%s", a + 32);
			}
			
			else if (arrN[X] >= 'A' && arrN[X] <= 'Z'){
				printf("%s", a - 32);
			}
		return 0;
	}
	
//5 3 Hello 0 1 3
//A = 65, a = 97, selisih = 32
