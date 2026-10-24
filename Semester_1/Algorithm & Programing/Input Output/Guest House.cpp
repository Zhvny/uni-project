#include <stdio.h>

int main() {
    double income[12]; // Array untuk menyimpan pendapatan bulanan
    double total_income = 0.0;
    double tax, building_cost, net_income;

    // Input pendapatan bulanan
    for (int i = 0; i < 12; i++) {
        scanf("%lf", &income[i]); // Membaca pendapatan bulanan
        total_income += income[i]; // Menjumlahkan pendapatan bulanan
    }

    // Hitung pajak pendapatan tahunan (15% dari total pendapatan)
    tax = total_income * 0.15;

    // Hitung biaya pengurusan gedung (5% dari total pendapatan bulanan dikali 12)
    building_cost = total_income * 0.05; // Biaya bulanan
    building_cost *= 12; // Biaya tahunan

    // Hitung sisa pendapatan bersih
    net_income = total_income - tax - building_cost;

    // Output hasil dengan presisi 2 digit di belakang koma
    printf("%.2lf\n", tax); // Mencetak pajak pendapatan
    printf("%.2lf\n", building_cost); // Mencetak biaya pengurusan gedung
    printf("%.2lf\n", net_income); // Mencetak sisa pendapatan bersih

    return 0;
}

