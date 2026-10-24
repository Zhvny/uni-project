#include <stdio.h>

// a dan b = passing parameter by reference (pakai bintang)
// x dan y = passing parameter by value (tanpa bintang)
void swapValues(int* a, int* b, int* x, int* y) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);

    swapValues(&a, &b, &x, &y);

    printf("%d %d %d %d", a, b, x, y);

    return 0;
}
