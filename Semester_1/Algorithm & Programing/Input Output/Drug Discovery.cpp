#include <stdio.h>

void find_drug_chain(int T, char cases[][101]) {
    for (int t = 0; t < T; t++) {
        char *s = cases[t];
        int char_count[26] = {0};  // Array untuk menghitung kemunculan setiap karakter
        char result[101];          // Array untuk menyimpan string hasil
        int idx = 0;               // Indeks untuk string hasil

        // Hitung kemunculan setiap karakter
        for (int i = 0; s[i] != '\0'; i++) {
            char_count[s[i] - 'a']++;
        }

        // Bangun rantai obat dengan menambahkan pasangan dan karakter tunggal
        int has_pairs = 0;
        for (int i = 0; i < 26; i++) {
            int pair_count = char_count[i] / 2;
            int single_count = char_count[i] % 2;

            // Tambahkan pasangan karakter ke hasil
            for (int j = 0; j < pair_count; j++) {
                result[idx++] = 'a' + i;
                result[idx++] = 'a' + i;
            }

            // Tambahkan satu karakter jika ada
            if (single_count) {
                result[idx++] = 'a' + i;
            }

            if (pair_count > 0) {
                has_pairs = 1;
            }
        }

        // Akhiri string hasil dengan null-terminate
        result[idx] = '\0';

        // Keluarkan hasil untuk kasus ini
        if (has_pairs) {
            printf("Case %d: %s\n", t + 1, result);
        } else {
            printf("Case %d: N/A\n", t + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    // Array untuk menyimpan setiap string kasus uji (panjang maksimum 100)
    char cases[T][101];

    // Membaca string masukan
    for (int i = 0; i < T; i++) {
        scanf("%s", cases[i]);
    }

    // Panggil fungsi untuk menemukan dan mencetak rantai obat
    find_drug_chain(T, cases);

    return 0;
}

