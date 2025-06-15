#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Fungsi untuk mengacak isi papan permainan dengan candy
void generateBoard(char board[ROWS][COLS]) {
    char candies[] = {'A', 'B', 'C', 'D', 'E'};
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = candies[rand() % 5]; // Mengacak candy
        }
    }
}

// Menampilkan papan permainan
void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Swap candy pada dua posisi
void swapCandies(char board[ROWS][COLS], int r1, int c1, int r2, int c2) {
    char temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}

// Cek apakah ada 3 candy yang cocok dalam satu baris atau kolom
int checkMatches(char board[ROWS][COLS]) {
    int matchFound = 0;

    // Cek baris untuk 3 atau lebih candy yang sama
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 2; j++) {
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]) {
                matchFound = 1;
                board[i][j] = board[i][j+1] = board[i][j+2] = ' '; // Tandai sebagai kosong
            }
        }
    }

    // Cek kolom untuk 3 atau lebih candy yang sama
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS - 2; i++) {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]) {
                matchFound = 1;
                board[i][j] = board[i+1][j] = board[i+2][j] = ' '; // Tandai sebagai kosong
            }
        }
    }

    return matchFound;
}

// Mengisi ulang candy yang telah dihapus
void refillBoard(char board[ROWS][COLS]) {
    char candies[] = {'A', 'B', 'C', 'D', 'E'};
    
    for (int j = 0; j < COLS; j++) {
        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][j] == ' ') {
                for (int k = i; k > 0; k--) {
                    board[k][j] = board[k-1][j]; // Candy jatuh ke bawah
                }
                board[0][j] = candies[rand() % 5]; // Candy baru di atas
            }
        }
    }
}

int main() {
    char board[ROWS][COLS];
    int r1, c1, r2, c2;

    // Membuat papan permainan
    generateBoard(board);

    // Game loop
    while (1) {
        printBoard(board);

        // Input pengguna: pilih dua posisi untuk ditukar
        printf("Pilih candy pertama (baris kolom): ");
        scanf("%d %d", &r1, &c1);
        printf("Pilih candy kedua (baris kolom): ");
        scanf("%d %d", &r2, &c2);

        // Tukar candy
        swapCandies(board, r1, c1, r2, c2);

        // Cek apakah ada yang cocok
        if (checkMatches(board)) {
            printf("Ada yang cocok!\n");
            refillBoard(board); // Mengisi ulang papan
        } else {
            printf("Tidak ada yang cocok. Tukar lagi.\n");
            // Tukar kembali jika tidak ada yang cocok
            swapCandies(board, r1, c1, r2, c2);
        }
    }

    return 0;
}

