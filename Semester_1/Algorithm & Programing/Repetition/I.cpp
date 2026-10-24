#include<stdio.h>

int main()
{	

	
    int T, i, a, b=0, jo, li, bi, avg;
    
    scanf("%d", &T);
    scanf("%d %d %d", &jo, &li, &bi);
    int atot[T], btot[T], ctot[T];
    
    for (i = 0; i<T; i++) {
        scanf("%d", &a);
        b += a;
    }
    
    avg = (b + jo + li + bi) / (T+3);
    
    if (jo >= avg) {
    	printf("Jojo lolos\n");
	} else {
		printf("Jojo tidak lolos\n");
	}
	
	if (li >= avg) {
    	printf("Lili lolos\n");
	} else {
		printf("Lili tidak lolos\n");
	}
	
	if (bi >= avg) {
    	printf("Bibi lolos\n");
	} else {
		printf("Bibi tidak lolos\n");
	}
    
    
    return 0;
}
