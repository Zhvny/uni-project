#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	
//	int a[101] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
	
//	for(int i = 0; i < 5; i++){
//		scanf("%d", &a[i]);
//	}
//	
//	for(int i = 0; i < 5; i++){
//		printf("%d ", a[i]);
//	}
	
//	Buat Nyari Angka Dalam Data
//	int dicari;
//	scanf("%d", &dicari);
//	
//	for(int i = 0; i < 10; i++){
//		if(a[i] == dicari){
//			printf("%d\n", i);
//			break;
//		}
//		else{
//			printf("Not Found.\n");
//			break;
//		}
//	}
	
//	Buat Remove dalam Array
//	int dibuang;
//	scanf("%d", &dibuang);
//	
//	int size = sizeof(a) / sizeof(a[0]);
//
//	for(int j = 0; j < size; j++){
//		if(a[j] = dibuang){
//			for (int i = 0; i < size - 1; i++){
//    	    	a[i - 1] = a[i];
//    		}
//    		size--;
//		}
//	}
//
//    for (int i = 0; i < size; i++){
//        printf("%d ", a[i]);
//    }

//	Pointer
//	int a = 10;
//	int *ptr;
//	ptr = &a;
//	
//	printf("%d\n", *ptr);
//	
//	int **dptr;
//	dptr = &ptr;
//
//	printf("%d\n", **dptr);	
    
    
    int a = 10, b = 15;
    
    swap(&a, &b);
    
    printf("%d %d\n", a, b);
    
//	Cara Nyari Array 
//	printf("%d", *(a+2));
    
	return 0;
}
