#include <stdio.h>
#include <string.h>
#define SIZE 101

void replaceCharacter(char *string, char *oldChar, char *newChar, int n){ 
	for (int i = 0; i < n; i++){
		for (int j = 0; string[j] != '\0'; j++){ 
			if (string[j] == oldChar[i]){
				string[j] = newChar[i]; 
			} 
		} 
	} 
}

int main(){
	FILE *fp = fopen("testdata.in", "r");

	int T;
	fscanf(fp, "%d", &T);
	
	for (int t = 0; t < T; t++) {
		char X[SIZE];
	    fscanf(fp, "%s", X);

	    int N;
	    fscanf(fp, "%d", &N);

	    char oldChar[27], newChar[27];
	    for (int i = 0; i < N; i++) {
	        fscanf(fp, " %c %c", &oldChar[i], &newChar[i]);
	    }
			
	    replaceCharacter(X, oldChar, newChar, N);
	    
	    int count[26] = {0};
	    for (int i = 0; X[i] != '\0'; i++) {
	        if (X[i] >= 'A' && X[i] <= 'Z') {
		        count[X[i] - 'A']++;
		    }
		}

	    for (int i = 0; i < 26; i++) {
	    	if (count[i] > 0) {
		          printf("%c %d\n", 'A' + i, count[i]);
		    	}
	    	}
		
		
		
		if (t != T - 1) {
	    	printf("\n");
	   	}
	}
	return 0;
}
