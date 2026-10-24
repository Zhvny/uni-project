package main

import "fmt"

func main(){
	day := 7
	
	// switch case mirip dengan C, harusnya mudah ya
	switch day {
	case 1:
		fmt.Println("Monday")
	case 2:
		fmt.Println("Tuesday")
	case 3:
		fmt.Println("Wednesday")
	default:
		fmt.Println("Invalid")
	}
}