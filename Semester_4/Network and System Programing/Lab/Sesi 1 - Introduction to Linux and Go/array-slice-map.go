package main

import "fmt"

func main(){
	// Array -> buat simpen banyak value dari tipe data yang sama
	var numberList [5]int = [5]int{1, 2, 3, 4, 5} //index mulai dari 0
	fmt.Println(numberList[3])
	var stringList [3]string = [3]string{"apple", "orange", "banana"}
	fmt.Println(stringList) // output: [apple orange banana]
	
	// Slice -> Sama aja kayak array, tapi ga perlu specify size nya
	var foodList []string = []string{"ramen", "bread", "meatball", "sausage", "fish"}
	fmt.Println(foodList) // output: [ramen bread meatball sausage fish]
	
	// Map -> dictionary di python. ada key, ada value -> [key]value
	var dictionary map[string]string = map[string]string{"cookie": "yummy", "milk": "cool",
			"cereal": "crunchy", "chocolate": "sweet"}
	fmt.Println(dictionary) 
	// output: map[cereal:crunchy chocolate:sweet cookie:yummy milk:cool]
	
	fmt.Println(dictionary["cookie"]) // output: yummy
}