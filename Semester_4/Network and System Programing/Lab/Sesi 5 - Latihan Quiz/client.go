// \s*\/\/.*

package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
	"time"
)

func main() {
	// bufio.NewReader(os.Stdin) dipakai supaya bisa baca input dari keyboard baris per baris
	reader := bufio.NewReader(os.Stdin)

	// minta user ketik username sebelum mulai kirim pesan
	fmt.Print("Enter your username: ")

	// ReadString('\n') baca input sampai user pencet [Enter]
	// return dua nilai: string-nya dan error-nya
	// error diabaikan pakai "_" karena kita assume input dari keyboard selalu valid
	username, _ := reader.ReadString('\n')

	// TrimSpace buang whitespace di kiri dan kanan string
	// termasuk "\n" yang ikut terbaca pas user pencet [Enter]
	// contoh: "Alice\n" => "Alice"
	username = strings.TrimSpace(username)

	// net.DialTimeout buat nyambung ke proxy lewat TCP di localhost:7070
	// kalau 10 detik ga nyambung-nyambung, otomatis error (timeout)
	dial, err := net.DialTimeout("tcp", "localhost:7070", 10*time.Second)
	if err != nil {
		fmt.Println("Connection failed:", err)
		return
	}
	// defer artinya dial.Close() dipanggil otomatis pas fungsi main() selesai
	// ini penting supaya koneksi TCP ditutup dengan bersih
	defer dial.Close()

	// loop tak terbatas supaya user bisa kirim banyak pesan tanpa reconnect
	for {
		fmt.Print("Enter message: ")

		// baca pesan dari keyboard sampai user pencet [Enter]
		msg, _ := reader.ReadString('\n')
		// buang "\n" di akhir
		msg = strings.TrimSpace(msg)

		// kalau user cuma pencet [Enter] tanpa ketik apa-apa, skip dan ulang loop
		if msg == "" {
			continue
		}

		// gabungin username dan pesan dengan pemisah "|"
		// format: "username|pesan", contoh: "Alice|hello"
		// ini supaya server bisa pisahin username dan pesannya nanti
		payload := String(username + "|" + msg)

		// kirim payload ke proxy lewat koneksi TCP yang sudah dibuka
		// WriteTo nulis data ke io.Writer (dalam hal ini, koneksi TCP)
		_, err = payload.WriteTo(dial)
		if err != nil {
			fmt.Println("Write error:", err)
			return
		}

		// tunggu dan baca balasan dari server (diteruskan lewat proxy)
		// Decode baca dari koneksi dan return Payload sesuai tipenya
		reply, err := Decode(dial)
		if err != nil {
			fmt.Println("Read error:", err)
			return
		}

		// tampilkan teks balasan dari server ke terminal
		fmt.Println(reply.String())
	}
}
