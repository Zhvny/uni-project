#include <stdio.h>

typedef struct {
    char huruf;
    int posisi;
} Block;
/* 
Block: Struktur ini mendefinisikan tipe data baru bernama Block, 
	   yang digunakan untuk menyimpan dua informasi:
	   1) letter: Huruf yang diinput oleh pengguna.
	   2) position: Posisi asli dari huruf tersebut dalam urutan input.
	   
	   Dengan menggunakan typedef, kita bisa langsung menyebut Block sebagai tipe 
	   data tanpa perlu mengetik struct Block setiap kali ingin mendeklarasikan 
	   variabel dari tipe ini.
*/
void bubbleSort(Block blocks[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (blocks[j].huruf > blocks[j+1].huruf) { // Tukar posisi blok jika salah urutan
                Block sementara = blocks[j];
                blocks[j] = blocks[j+1];
                blocks[j+1] = sementara;
            }
        }
    }
}

int main() {
    char x1, x2, x3;
    scanf(" %c %c %c", &x1, &x2, &x3);
    
    Block blocks[3] = {
        {x1, 1},
        {x2, 2},
        {x3, 3}
    };
/*
Bubble Sort adalah salah satu algoritma pengurutan (sorting) 
yang paling sederhana. Algoritma ini bekerja dengan cara berulang kali 
menukar elemen yang bersebelahan jika mereka berada dalam urutan yang salah. 
Proses ini dilakukan berulang-ulang hingga tidak ada lagi elemen yang perlu
ditukar, artinya daftar telah terurut.
*/
    bubbleSort(blocks, 3);
/*
Cara Kerja Bubble Sort:
	1) Perbandingan dan Pertukaran:
		- Algoritma memulai dengan membandingkan dua elemen pertama dalam daftar.
		- Jika elemen pertama lebih besar dari elemen kedua (dalam pengurutan menaik), 
		  maka kedua elemen tersebut ditukar. Jika tidak, biarkan saja.  
		- Proses ini diulangi untuk pasangan elemen berikutnya sampai akhir daftar.
		- Setelah satu iterasi penuh (loop luar), elemen terbesar akan berada di posisi terakhir 
		  (karena telah "mengambang" ke atas seperti gelembung—itulah asal nama bubble sort).
	2) Proses Iteratif:
		- Setelah iterasi pertama selesai, algoritma mengulangi proses untuk semua elemen kecuali 
		  elemen terakhir (karena elemen terbesar sudah di tempat yang benar).
		- Algoritma terus mengulang proses ini untuk elemen-elemen yang tersisa, mengurutkan satu 
		  elemen setiap iterasi, hingga seluruh daftar terurut.
*/
    printf("%d %d %d\n", blocks[0].posisi, blocks[1].posisi, blocks[2].posisi);
    
    return 0;
}


/*
Cara Gampang


#include <stdio.h>

int main() {
    char huruf[3];
    int posisi[3] = {1, 2, 3};

    // baca 3 karakter dari input
    scanf(" %c %c %c", &huruf[0], &huruf[1], &huruf[2]);

    // ngurutin karakter n posisi
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (huruf[j] > huruf[j + 1]) {
                // Tukar karakter
                char huruf_sementara = huruf[j];
                huruf[j] = huruf[j + 1];
                huruf[j + 1] = huruf_sementara;

                // tuker posisi
                int posisi_sementara = posisi[j];
                posisi[j] = posisi[j + 1];
                posisi[j + 1] = posisi_sementara;
            }
        }
    }

    printf("%d %d %d\n", posisi[0], posisi[1], posisi[2]);

    return 0;
}
*/
