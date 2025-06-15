#include <stdio.h>

int main() {
    int N, K, T;           //N =  . K = Kapasitas Nafas.
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N, &K);

        char petak[N+1];
        scanf("%s", petak);

        int jojo = 0;       // Posisi Jojo
        int lantai = 1;
        int nafas = K;
        for (int i = 2; i <= N; i++) {
            if(petak[jojo] == '0' && petak[i] == '0') {
                nafas--;
            }

            else if(petak[jojo] == '1' && petak[i] == '0') {
                if(lantai == 1) {
                    lantai++;
                    nafas = K;  // Bernafas Dengan Lege
                }
                else {
                    lantai--;
                }
            }

            else if(petak[jojo] == '0' && petak[i] == '1') {
                nafas--;
            }

            else if(petak[jojo] == '1' && petak[i] == '1') {
                if(lantai == 1) {
                    lantai++;
                    nafas = K;  // Bernafas Dengan Lega
                }
                else {
                    lantai--;
                }
            }

            jojo = i;
            // printf("napas gemink: %d\n", nafas);
            if (nafas == 0) break;

        }
        if(nafas == 0) {
            printf("Ded\n");
        }

        else {
            printf("Ajay\n");
        }
    }
    return 0;
}



