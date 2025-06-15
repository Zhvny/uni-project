#include<stdio.h>

int main(){
    double a, b, c, d;
    for(int i = 0; i <= 2; i++){
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    
    a = 2 * a;
    b = 2 * b;
    c = 2 * c;
    
    printf("%.2lf\n", a + b + c + d);
    }
    return 0;
    
}