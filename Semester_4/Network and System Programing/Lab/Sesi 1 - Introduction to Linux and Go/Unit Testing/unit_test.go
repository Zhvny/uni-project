package main

/* Ada beberapa rules untuk melakukan Unit testing, yaitu file testing harus diakhiri dengan “_test.go” dan 
   nama function untuk testing harus diawali dengan “Test” dan harus menggunakan parameter “*testing.T” */

import (
	"testing"
)

// name function harus diawali dengan "Test" dan parameter harus ada "*testing.T"
func TestAdd(t *testing.T) {
	result := addNumber(3, 3)
	expected := 6

	if result != expected { // kalau hasil tdk sama dengan prediksi, maka akan output error
		t.Errorf("Expected %d but got %d", expected, result)
	}
}