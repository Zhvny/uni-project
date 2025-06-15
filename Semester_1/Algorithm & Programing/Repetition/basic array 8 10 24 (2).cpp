#include <stdio.h>

int main() {
    int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    int b[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    int c[4][4] = {};

    for(int baris = 0; baris < 4; baris++) {
        for(int kolom = 0; kolom < 4; kolom++) {
            c[baris][kolom] = a[baris][kolom] + b[baris][kolom];
            printf("%2d\n", c[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}
