package main

import (
	"fmt"
	"net"
	"strings"
	"time"
)

func main() {
	// net.Listen buka port TCP 6060 untuk menerima koneksi dari proxy
	listener, err := net.Listen("tcp", "localhost:6060")
	if err != nil {
		fmt.Println("Server error:", err)
		return
	}
	// tutup listener saat program selesai
	defer listener.Close()

	fmt.Println("Server listening on localhost:6060")

	// loop tak terbatas untuk terus terima koneksi baru dari proxy
	for {
		// Accept() blok sampai ada koneksi masuk dari proxy
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Accept error:", err)
			// continue supaya server tetap jalan meski 1 koneksi gagal
			continue
		}
		// jalankan handler di goroutine terpisah supaya concurrent
		go handleClientDynamic(conn)
	}
}

// handleClientDynamic proses pesan dari proxy dan kirim balasan
func handleClientDynamic(conn net.Conn) {
	// tutup koneksi saat fungsi selesai
	defer conn.Close()

	// SetDeadline pasang batas waktu 1 detik untuk operasi baca/tulis
	// kalau dalam 1 detik tidak ada aktivitas, koneksi otomatis ditutup
	// ini buat proteksi supaya koneksi idle tidak menumpuk di server
	err := conn.SetDeadline(time.Now().Add(1 * time.Second))
	if err != nil {
		fmt.Println(err)
	}

	// loop untuk terima lebih dari satu pesan per koneksi
	for {
		// decode pesan yang dikirim proxy ke server
		payload, err := Decode(conn)
		if err != nil {
			fmt.Println("Decode error:", err)
			return
		}

		// pisahkan string "username|pesan" jadi dua bagian
		// SplitN(..., 2) artinya split maksimal 2 bagian saja
		// supaya kalau pesannya ada "|" di dalamnya, tidak kepotong
		parts := strings.SplitN(payload.String(), "|", 2)
		// kalau format tidak sesuai (tidak ada "|"), hentikan
		if len(parts) != 2 {
			return
		}
		// ekstrak username dan pesan dari hasil split
		clientName, message := parts[0], parts[1]

		// cek apakah pesan mengandung huruf kapital
		// logika: kalau ada huruf antara 'A' dan 'Z', berarti ada kapital
		hasUpper := false
		for _, r := range message {
			if r >= 'A' && r <= 'Z' {
				hasUpper = true
				break // stop loop begitu ketemu 1 huruf kapital
			}
		}

		// konversi pesan sesuai kondisi:
		// ada huruf kapital => ubah semua ke lowercase
		// tidak ada huruf kapital => ubah semua ke uppercase
		var converted string
		if hasUpper {
			converted = strings.ToLower(message)
		} else {
			converted = strings.ToUpper(message)
		}

		// buat balasan dengan format "Server Reply to <username>: <pesan>"
		// Sprintf format string dan return hasilnya sebagai String payload
		reply := String(fmt.Sprintf("Server Reply to %s: %s", clientName, converted))

		// kirim balasan ke proxy (yang nanti akan diteruskan ke client)
		_, err = reply.WriteTo(conn)
		if err != nil {
			fmt.Println("Write error:", err)
			return
		}
	}
}
