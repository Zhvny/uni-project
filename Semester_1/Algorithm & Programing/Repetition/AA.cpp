#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int lempar[T];

    for (int i = 0; i < T; i++) {
        scanf("%d", &lempar[i]);
    }

    int posisi = 0;

    int tangga[3][2] = {{9, 21}, {33, 42}, {76, 92}};   // 3 tangga 2 posisi (awal n akir)
    int ulr[3][2] = {{53, 37}, {80, 59}, {97, 88}};     // 3 tangga 2 posisi (awal n meluncr)

    for (int i = 0; i < T; i++) {
        posisi += lempar[i];

        for (int j = 0; j < 3; j++) {
            if (posisi == tangga[j][0]) {
                posisi = tangga[j][1];
            }
        }

        for (int j = 0; j < 3; j++) {
            if (posisi == ulr[j][0]) {
                posisi = ulr[j][1];
            }
        }
    }

    printf("%d\n", posisi);
    return 0;
}

