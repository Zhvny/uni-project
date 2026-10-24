#include <stdio.h>
#include <string.h>

typedef struct koleksi{
	int key;
	int value;
} kol; 

int main(){
	kol dictionary[100];
	
	for(int i = 0; i < 10; i++){
		scanf("%d %d", &dictionary[i].key, &dictionary[i].value);
	}
	
	for(int i = 0; i < 10; i++){
		printf("Key: %d, Value: %d\n", dictionary[i].key, dictionary[i].value);
	}
	
	return 0;
}

//	Testcase
//	1 20
//	2 30
//	3 40
//	4 50
//	5 60
//	6 70
//	7 80
//	8 90
//	9 100
//	10 110
