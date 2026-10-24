package main

import "fmt"

func main() {
	fmt.Println("Starting")

	defer fmt.Println("Program Ended")

	fmt.Println("Running")

	defer fmt.Println("Ending Program")
}