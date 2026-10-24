package main

import "fmt"

func main(){
	// string biasa, seperti 
	var str string = "Network and System Programming" // String
	
	// integer biasa, hanya bisa bilangan bulat
	var integer int = 61 
	
	// float ada 2, yaitu float32 dan float64. Secara singkat, float64 lebih akurat dari 
	// float32, jadi lebih aman kalau pake float64 aja
	var float float64 = 1.64 
	
	// boolean biasa, true/false
	var boolean bool = true
	
	// printing with format (printf)
	fmt.Printf("%s and %d and %.2f and %t \n", str, integer, float, boolean)
}