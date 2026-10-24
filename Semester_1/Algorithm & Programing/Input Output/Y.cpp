#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
    long long int n;
    int p;
    
    scanf("%lld %d", &n, &p);
    
    double hasil = p * 0.01 * n;
    printf("%.2lf\n", hasil);
    }
    return 0;
    
}