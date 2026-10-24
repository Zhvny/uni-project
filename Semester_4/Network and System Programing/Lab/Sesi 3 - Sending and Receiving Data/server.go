package main

import (
	"bufio"
	"fmt"
	"net"
)

func main() {
	listener, err := net.Listen("tcp", "localhost:1234")

	// Ini wajib untuk menangani error yang mungkin terjadi saat membuat listener
	if err != nil {
		// Handle error
		fmt.Println("Error starting server:", err)
		return
	}

	defer listener.Close()

	for {
		conn, err := listener.Accept()

		if err != nil {
			fmt.Println("Error accepting connection:", err)
			return
		}

		// go handleClientFixed(conn)
		// go handleClientScanner(conn)
		go handleClientDynamic(conn)
	}
}

func handleClientFixed(conn net.Conn) {
	defer conn.Close()

	buffer := make([]byte, 1024)
	n, err := conn.Read(buffer)

	if err != nil {
		fmt.Println("Error reading from connection:", err)
		return
	}

	fmt.Printf("Received: %s, byte size %d\n", buffer[:n], n)
}

func handleClientScanner(conn net.Conn) {
	defer conn.Close()

	scanner := bufio.NewScanner(conn)
	scanner.Split(bufio.ScanLines)

	for scanner.Scan() {
		fmt.Printf("Received: %s\n", scanner.Text())
	}
}

func handleClientDynamic(conn net.Conn) {
	defer conn.Close()

	Payload, err := decode(conn)

	if err != nil {
		fmt.Println("Error decoding payload:", err)
		return
	}
	fmt.Printf("Received payload: %v\n", Payload)
}
