#include <stdio.h>

int main() {
    long long int a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    long long int hasil_l = a * b;
    long long int hasil_r = c + d;

    if (hasil_l > hasil_r) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

