package main

import (
	"fmt"
	"net"
)

func main() {
	// net.Listen buka port TCP 7070 untuk menerima koneksi dari client
	listener, err := net.Listen("tcp", "localhost:7070")
	if err != nil {
		fmt.Println("Proxy error:", err)
		return
	}
	// tutup listener saat program selesai supaya port dilepas
	defer listener.Close()

	fmt.Println("Proxy listening on localhost:7070")

	// loop tak terbatas untuk terus menerima koneksi baru dari client
	for {
		// Accept() blok (nunggu) sampai ada client yang nyambung
		// return net.Conn yang mewakili koneksi dengan client tersebut
		clientConn, err := listener.Accept()
		if err != nil {
			fmt.Println("Accept error:", err)
			// continue (bukan return) supaya proxy tetap jalan walau 1 koneksi gagal
			continue
		}
		// "go" jalankan handleProxyConn di goroutine terpisah
		// supaya proxy bisa handle banyak client secara bersamaan (concurrent)
		// tanpa goroutine, proxy harus nunggu client pertama selesai dulu
		go handleProxyConn(clientConn)
	}
}

// handleProxyConn tangani satu koneksi client dari awal sampai selesai
func handleProxyConn(clientConn net.Conn) {
	// tutup koneksi client saat fungsi ini selesai (apapun sebabnya)
	defer clientConn.Close()

	// loop supaya satu client bisa kirim banyak pesan
	for {
		// decode pesan yang dikirim client ke proxy
		payload, err := Decode(clientConn)
		if err != nil {
			fmt.Println("Client decode error:", err)
			return
		}

		// buka koneksi baru ke server untuk setiap pesan
		// proxy tidak punya koneksi permanen ke server
		serverConn, err := net.Dial("tcp", "localhost:6060")
		if err != nil {
			fmt.Println("Dial server error:", err)
			return
		}

		// teruskan pesan dari client ke server
		_, err = payload.WriteTo(serverConn)
		if err != nil {
			fmt.Println("Forward error:", err)
			serverConn.Close()
			return
		}

		// baca balasan dari server
		reply, err := Decode(serverConn)

		// tutup koneksi ke server setelah dapat balasan
		// koneksi ke server hanya hidup selama 1 request-reply
		serverConn.Close()

		if err != nil {
			fmt.Println("Server reply error: Server has been closed by timeout")
			return
		}

		// kirim balasan server ke client
		_, err = reply.WriteTo(clientConn)
		if err != nil {
			fmt.Println("Return error:", err)
			return
		}
	}
}
