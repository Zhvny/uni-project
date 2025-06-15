#include <stdio.h>

int main(){
	int T = 3;
	
	for (int j = 0; j < T; j++){
		int N;
		scanf("%d", &N);
	
		int count = 0;
		char S[101];
		for (int i = 0; i <= N; i++){
			scanf("%c", &S[i]);
			count++;
		}
		printf("%c%c\n", S[count - 1], S[1]);
	}
	return 0;
}

//5 abcde 8 ujhgtfyh 3 qwe
