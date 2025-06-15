#include<stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int k, m, n;
	
for(int i = 1; i < t + 1; i++){
	scanf("%d %d %d", &k, &m, &n);
	
		if(k > m + n){
			printf("Case #%d: no\n", i);
		}
	
		else{
			printf("Case #%d: yes\n", i);
		}
	}

	return 0;
}
