package main

import "fmt"

func main(){
	for i := 0; i < 5; i++ {
			fmt.Println("number : ", i)
	}


	// Cara While di GoLang
	number := 0
	for number < 10 {
		fmt.Println(number)
		number++
	}
}