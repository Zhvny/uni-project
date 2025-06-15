#include <stdio.h>

int main() {
    char huruf[3];
    int posisi[3] = {1, 2, 3};
    scanf(" %c %c %c", &huruf[0], &huruf[1], &huruf[2]);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (huruf[j] > huruf[j + 1]) {

                char huruf_sementara = huruf[j];
                huruf[j] = huruf[j + 1];
                huruf[j + 1] = huruf_sementara;
                
                int posisi_sementara = posisi[j];
                posisi[j] = posisi[j + 1];
                posisi[j + 1] = posisi_sementara;
            }
        }
    }

    printf("%d %d %d\n", posisi[0], posisi[1], posisi[2]);

    return 0;
}
