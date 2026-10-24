package main

import (
	"fmt"
	"net"
)

func main() {
	dial, err := net.Dial("tcp", "localhost:1234")

	if err != nil {
		fmt.Println("Error connecting to server:", err)
		return
	}

	// data := []byte("Testing Data")
	// _, err = dial.Write(payload)
	payload := Binary("Testing Data")
	_, err = payload.WriteTo(dial)

	if err != nil {
		fmt.Println("Error writing to server:", err)
		return
	}

	defer dial.Close()
}
