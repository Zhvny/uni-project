#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);

    int angka[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &angka[i]);
    }

    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += angka[i];
    }

    double total = (double) jumlah / n;
    printf("%d %llf", jumlah, average);
    
    int min, max;
    
    for (int i = 0; i < n; i++) {
        if(angka[i] < min){
        	min = angka[i];
		}
		else if(angka[i] > max){
			max = angka[i];
		}
    }
    
    return 0;
}

