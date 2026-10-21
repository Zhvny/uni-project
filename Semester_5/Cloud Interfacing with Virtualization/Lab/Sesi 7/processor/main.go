package main

import (
	"encoding/json"
	"fmt"
	"time"

	"servicebus-demo/azure"
	"servicebus-demo/shared"
)

func main() {
	for {
		msg, err := azure.ReceiveMessage()
		if err != nil {
			fmt.Println("receive error:", err)
			time.Sleep(time.Second)
			continue
		}

		var order shared.Order
		if err := json.Unmarshal(msg.Body, &order); err != nil {
			fmt.Println("unmarshal error:", err)
			_ = azure.CompleteMessage(msg)
			continue
		}

		fmt.Printf("Received Order %d\n", order.OrderID)
		fmt.Println("Processing...")

		time.Sleep(10 * time.Second)

		fmt.Printf("Order %d Success\n", order.OrderID)

		if err := azure.CompleteMessage(msg); err != nil {
			fmt.Println("complete error:", err)
		}
	}
}