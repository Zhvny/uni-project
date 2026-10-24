#include <stdio.h>

int cari_waktu_yang_sama(int x, int y, int k) {
    for (int t = 0; t <= 100; t++) {
        if (x + t == k && y - t == k) {
            return t;
        }
    }
    return -1;
}

int main() {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    int hasil = cari_waktu_yang_sama(x, y, k);
    printf("%d\n", hasil);
    
    return 0;
}

