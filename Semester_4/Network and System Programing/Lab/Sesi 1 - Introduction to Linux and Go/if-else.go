package main

import "fmt"

func main(){
	number := -5
	// [ number := -5 ] sama saja dengan
	// [ var number int = -5 ]
	// bedanya adalah := akan mengasumsikan tipe data sesuai value yang didapatkan
	// := juga hanya bisa digunakan dalam function, tidak bisa di luar, sedangkan var bisa dipakai di luar function
		
	// If-else statement seperti biasa, mirip dengan bahasa-bahasa lain
	if number < 0 {
		fmt.Println("negative number")
	} else if number > 0 {
		fmt.Println("positive number")
	} else {
		fmt.Println("zero")
	}
}