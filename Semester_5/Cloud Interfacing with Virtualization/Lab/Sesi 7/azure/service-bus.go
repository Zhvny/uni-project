package azure

import (
	"context"
	"fmt"

	"github.com/Azure/azure-sdk-for-go/sdk/azidentity"
	"github.com/Azure/azure-sdk-for-go/sdk/messaging/azservicebus"
)

var cred *azidentity.InteractiveBrowserCredential
var client *azservicebus.Client
var receiver *azservicebus.Receiver

func initClient() error {
	if client != nil {
		return nil
	}
	var err error

	cred, err = azidentity.NewInteractiveBrowserCredential(nil)
	if err != nil {
		return err
	}

	client, err = azservicebus.NewClient("sb-sesi7-kevin.servicebus.windows.net", cred, nil)
	if err != nil {
		return err
	}
	return nil
}

func getReceiver() (*azservicebus.Receiver, error) {
	if err := initClient(); err != nil {
		return nil, err
	}
	if receiver == nil {
		r, err := client.NewReceiverForQueue("orders", nil)
		if err != nil {
			return nil, err
		}
		receiver = r
	}
	return receiver, nil
}

// SendMessage sends a message body to the "orders" queue.
func SendMessage(body []byte) error {
	if err := initClient(); err != nil {
		return err
	}

	sender, err := client.NewSender("orders", nil)
	if err != nil {
		return err
	}
	defer sender.Close(context.TODO())

	sbMessage := &azservicebus.Message{
		Body: body,
	}
	return sender.SendMessage(context.TODO(), sbMessage, nil)
}

// ReceiveMessage receives a single message from the "orders" queue.
func ReceiveMessage() (*azservicebus.ReceivedMessage, error) {
	r, err := getReceiver()
	if err != nil {
		return nil, err
	}

	messages, err := r.ReceiveMessages(context.TODO(), 1, nil)
	if err != nil {
		return nil, err
	}
	if len(messages) == 0 {
		return nil, fmt.Errorf("no messages received")
	}
	return messages[0], nil
}

// CompleteMessage completes (settles) a received message.
func CompleteMessage(msg *azservicebus.ReceivedMessage) error {
	r, err := getReceiver()
	if err != nil {
		return err
	}
	return r.CompleteMessage(context.TODO(), msg, nil)
}