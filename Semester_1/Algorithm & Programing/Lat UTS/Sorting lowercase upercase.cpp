#include <stdio.h>

int main(){
	char input[100];
	char temp;
//	char ascii = 'a';
	
	scanf("%s", input);
	
	int n = 0;
	while(input[n] != '\0') {
		n++;
	}
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i -1; j++) {
			if((input[j] > input[j + 1]) || 
				(input[j] >= 'a' && input[j + 1] < 'a' && input[j] - 32 >= input[j + 1])) {
				temp = input [j];
				input[j] = input[j + 1];
				input [j + 1] = temp;
			}
		}
	}
	
	char sorted[100];
    int upper_index = 0;
    int lower_index = n;

    for (int i = 0; i < n; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            sorted[upper_index++] = input[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            sorted[lower_index++] = input[i];
        }
    }

    sorted[upper_index + lower_index] = '\0';
//	printf("%d\n", ascii);
	printf("%s\n", input);
	printf("%s\n", sorted);
	return 0;
}
