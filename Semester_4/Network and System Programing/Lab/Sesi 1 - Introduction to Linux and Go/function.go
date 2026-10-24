package main

import "fmt"

func main() {
	fmt.Println("Add your numbers!")
	
	a := 3
	b := 2
	
	answer := addNumbers(a, b)
	fmt.Println("answer :", answer)
}

// func [name]([parameters])[return type] {}
func addNumbers(a int, b int) int { // return type ditulis setelah parameters
	return a + b
}