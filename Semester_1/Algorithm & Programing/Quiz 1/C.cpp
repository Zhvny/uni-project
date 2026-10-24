#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	
	int N;
	for (int i = 0; i < T; i++){
		scanf("%d", &N);
		
		int A[N]; 
		long long int jojo;
		long long int lili;
		for (int j = 1; j <= N; j++){
			scanf("%d", &A[j]);
		
			if (j % 2 == 0){
				if ( A[j] % 2 == 0){
					jojo ++;
				}
			}
			
			else if {
				if ( A[j] % 2 != 1){
					lili ++;
				}
			}
		} 
		
		if (jojo % 2 == 0 && lili % 2 != 0) {
		}
			printf("Case #%d: :)\n", i + 1);
		}
		
		else if (jojo % 2 != 0 && lili % 2 == 0){
			printf("Case #%d: :(\n", i + 1);			
		}
		
		else{
			printf("Case #%d: :|\n", i + 1);
		}
		}
		return 0;
	}
	
//4 3 0 1 2 3 1 2 3 0 2 4 3 1 3 5
//(jojo % 2 == 0 && lili % 2 != 0) || (jojo % 2 != 0 && lili % 2 == 0)

