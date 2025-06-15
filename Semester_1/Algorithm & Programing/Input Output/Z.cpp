#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++){
    double a, b, c, d;
    
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    getchar();
    
    a = 2 * a;
    b = 2 * b;
    c = 4 * c / 3;
    d = d / 2;

    printf("%.2lf\n", a + b + c + d);
    }
    return 0;
    
}
