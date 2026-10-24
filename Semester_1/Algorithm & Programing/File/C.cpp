#include <stdio.h>
#include <string.h>
#define SIZE 1001

int main(){
    FILE *fp;
    fp = fopen("testdata.in", "r");
    
    
    int A, B;
    fscanf(fp, "%d %d", &A, &B);
    
    printf("%d\n", A + B);
    
    return 0;
}
