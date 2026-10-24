#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int hasil = 0;

    for (int i = 0; i < N; i++) {
        int tc, ts, tv;
        scanf("%d %d %d", &tc, &ts, &tv);

        if (ts > tv) {
            hasil++;
        }
    }
    printf("%d\n", hasil);

    return 0;
}
