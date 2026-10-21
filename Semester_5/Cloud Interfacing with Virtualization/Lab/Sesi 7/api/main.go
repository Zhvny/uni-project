package main

import (
	"encoding/json"
	"fmt"
	"net/http"

	"servicebus-demo/azure"
	"servicebus-demo/shared"
)

func createOrder(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "method not allowed", http.StatusMethodNotAllowed)
		return
	}

	order := shared.Order{
		OrderID:  1001,
		Product:  "Mechanical Keyboard",
		Quantity: 1,
	}

	payload, err := json.Marshal(order)
	if err != nil {
		http.Error(w, "failed to marshal order", http.StatusInternalServerError)
		return
	}

	if err := azure.SendMessage(payload); err != nil {
		http.Error(w, "failed to send order", http.StatusInternalServerError)
		return
	}

	w.Write([]byte("Order submitted to queue"))
}

func main() {
	http.HandleFunc("/orders", createOrder)

	fmt.Println("API running on :8080")
	if err := http.ListenAndServe(":8080", nil); err != nil {
		panic(err)
	}
}