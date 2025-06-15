import pandas as pd                # Import library pandas untuk membaca file Excel
import numpy as np                 # Import library numpy untuk operasi matematika
import matplotlib.pyplot as plt    # Import matplotlib untuk membuat grafik

# --- FUNGSI ---
def kuadratik_model(x, y):
    matriks = np.vstack([x**2, x, np.ones(len(x))]).T  # Buat matriks desain dengan x^2, x, dan 1 (konstanta)
    data_y = y[:, np.newaxis]                          # Ubah y menjadi bentuk kolom agar bisa dikalikan
    koef = np.linalg.inv(matriks.T @ matriks) @ matriks.T @ data_y  # Rumus regresi kuadratik (least square)
    return koef.flatten()                              # Kembalikan koefisien sebagai array 1 dimensi

def tampilkan_model_kuadratik(x, a, b, c):
    for i in range(len(x)):
        prediksi = a * x[i]**2 + b * x[i] + c          # Hitung prediksi dari model kuadratik
        print(f"Bulan {i+1} (x = {x[i]}):")            # Cetak informasi bulan ke-i
        print(f"  Model Kuadratik: {a:.3f} * {x[i]}^2 + {b:.3f} * {x[i]} + {c:.3f} = {prediksi:.3f}")

def deret_taylor(a, b, c, x_titik, x_uji):
    f_x = a*x_titik**2 + b*x_titik + c                # Nilai fungsi f(x) pada titik tengah
    f_1 = 2*a*x_titik + b                             # Turunan pertama dari fungsi f(x)
    f_2 = 2*a                                         # Turunan kedua dari fungsi f(x)
    prediksi = f_x + f_1 * (x_uji - x_titik) + 0.5 * f_2 * (x_uji - x_titik)**2  # Rumus deret Taylor orde 2
    return f_x, f_1, f_2, prediksi                    # Kembalikan semua hasil turunan dan prediksi

def newton_raphson(f, f_prime, x0, tol=0.001, max_iter=1000):
    for i in range(max_iter):
        x1 = x0 - f(x0) / f_prime(x0)                 # Rumus metode Newton-Raphson
        print(f'Iterasi {i+1}: {x1:.3f}')              # Tampilkan hasil setiap iterasi
        if abs(f(x1)) < tol:                          # Cek apakah hasil sudah mendekati nol
            print(f"Produksi melebihi 25000 tas pada bulan: {x1:.3f}")
            return x1                                 # Jika ya, kembalikan bulan tersebut
        x0 = x1                                       # Update nilai x0 untuk iterasi berikutnya
    return None                                       # Jika tidak ditemukan solusi, kembalikan None

# --- MAIN ---
print("PROBLEM 1")
data = pd.read_excel('data.xlsx')                    # Baca data dari file Excel
x = np.arange(1, 145)                                # Buat array x dari 1 sampai 144 (bulan)
y = data.iloc[0].values.astype(float)               # Ambil baris pertama dari data sebagai array y

a, b, c = kuadratik_model(x, y)                     # Hitung koefisien model kuadratik
hasil_prediksi = a * x**2 + b * x + c               # Hitung hasil prediksi model kuadratik
print(f"Parameter model kuadratik: a = {a:.3f}, b = {b:.3f}, c = {c:.3f}")
tampilkan_model_kuadratik(x, a, b, c)               # Tampilkan hasil model per bulan

plt.plot(x, y, 'o', label='Data Produksi Asli')      # Plot data asli
plt.plot(x, hasil_prediksi, 'r--', label='Model Kuadratik')  # Plot hasil prediksi dari model
plt.xlabel('Bulan')
plt.ylabel('Produksi')
plt.title('Produksi Bulanan dan Model Tren')
plt.legend()
plt.grid(True)
plt.show()                                           # Tampilkan grafik

print("\nPROBLEM 2")
x_mean = x.mean()                                    # Hitung rata-rata dari x sebagai titik pusat Taylor
f_x, f_1, f_2, prediksi = deret_taylor(a, b, c, x_mean, 1)  # Hitung nilai deret Taylor di x=1
print(f"Deret Taylor: f(x) = {f_x:.3f} + {f_1:.3f}(x - {x_mean:.3f}) + 0.5*{f_2:.4f}(x - {x_mean:.3f})^2")
print(f"Nilai prediksi pada bulan pertama: {prediksi:.3f}")
aktual = y[0]                                        # Nilai aktual produksi pada bulan pertama
akurasi = 100 - abs(prediksi - aktual) / aktual * 100  # Hitung akurasi prediksi
print(f"Akurasi deret Taylor (pada bulan pertama): {akurasi:.3f}%")

print("\nPROBLEM 3")
def f(x): return a * x**2 + b * x + (c - 25000)      # Fungsi untuk mencari kapan produksi = 25000

def f_prime(x): return 2 * a * x + b                # Turunan dari fungsi f(x)

bulan_lebih = newton_raphson(f, f_prime, 100)        # Mulai Newton-Raphson dari x = 100
if bulan_lebih:
    print(f"Mulai membangun gudang baru pada bulan: {bulan_lebih - 13:.3f}")  # Cetak hasil akhir
else:
    print("Tidak ditemukan solusi dalam batas iterasi.")
