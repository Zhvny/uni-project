#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 101

int main(){
	FILE *fp = fopen("testdata_e.in", "r");
	
	int T;
	fscanf(fp, "%d", &T);

	for (int t = 1; t <= T; t++) {
	    int N;
	    fscanf(fp, "%d", &N);
	
	    int X[SIZE];
	    for (int i = 0; i < N; i++) {
	        fscanf(fp, "%d", &X[i]);
	    }
	
	    int perimeter = 2 * 2 * (X[0] + X[N - 1]);
	    perimeter += 2 * N;
	    for (int i = 0; i < N - 1; i++) {
	        perimeter += abs(X[i] - X[i + 1]);
	    }
	
	    int area = 0;
	    for (int i = 0; i < N; i++) {
	        area += 2 * 2 * X[i];
	    }
	
	    printf("Case #%d: %d %d\n", t, perimeter, area);
	}
	return 0;
}
