package shared

type Order struct {
	OrderID  int    `json:"orderId"`
	Product  string `json:"product"`
	Quantity int    `json:"quantity"`
}