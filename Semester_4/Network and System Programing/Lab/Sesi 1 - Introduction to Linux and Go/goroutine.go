package main

import (
	"fmt"
	"time" // untuk function2 yang berhubungan dengan waktu seperti time.sleep, time.Second
)

// init array
var fruits [5]string = [5]string{
	"apel",
	"anggur",
	"pisang",
	"duren",
	"jeruk",
}

func main() {
	go printLetters()
	go printfruit(fruits[:]) // [:] artinya mengambil semua anggota dari array, syntax nya mirip dengan array di python. [1:] artinya mulai dari index 1, [:4] artinya mulai dari in-dex 0 dan stop di index 4.

	fmt.Scanln() // digunakan agar ada cukup waktu untuk function kita berjalan (biar programnya ga langsung stop)
}

// function untuk print huruf
func printLetters() {
	for i := 'A'; i <= 'E'; i++ {
		fmt.Printf("%c\n", i)
		time.Sleep(1 * time.Second)
	}
}

// function untuk print anggota dari array
func printfruit(arr []string) {
	for i := range arr { // for untuk memprint anggota array
		fmt.Printf("%s\n", arr[i])
		time.Sleep(1 * time.Second)
	}
}