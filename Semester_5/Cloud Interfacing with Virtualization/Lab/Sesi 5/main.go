package main

import (
	"context"
	"encoding/json"
	"errors"
	"log"
	"net/http"
	"os"

	"github.com/Azure/azure-sdk-for-go/sdk/azcore"
	"github.com/Azure/azure-sdk-for-go/sdk/data/azcosmos"
)

// Connection string diambil dari environment, bukan ditulis di kode.
// PowerShell: $env:COSMOS_CONNECTION_STRING = "AccountEndpoint=...;AccountKey=..."
func connectionString() string {
	connStr := os.Getenv("COSMOS_CONNECTION_STRING")
	if connStr == "" {
		log.Fatal("COSMOS_CONNECTION_STRING kosong; set dulu environment variable-nya")
	}
	return connStr
}

type Item struct {
	ID       string `json:"id"`
	Name     string `json:"name"`
	Category string `json:"category"`
}

func isConflict(err error) bool {
	var re *azcore.ResponseError
	return errors.As(err, &re) && re.StatusCode == http.StatusConflict
}

func main() {
	ctx := context.Background()

	client, err := azcosmos.NewClientFromConnectionString(connectionString(), nil)

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	db, err := client.NewDatabase("testDB")

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	if _, err := client.CreateDatabase(ctx, azcosmos.DatabaseProperties{ID: "testDB"}, nil); err != nil && !isConflict(err) {
		log.Fatalf("%s\n", err)
	}

	if _, err := db.CreateContainer(ctx, azcosmos.ContainerProperties{
		ID: "product",
		PartitionKeyDefinition: azcosmos.PartitionKeyDefinition{
			Paths: []string{"/category"},
		},
	}, nil); err != nil && !isConflict(err) {
		log.Fatalf("%s\n", err)
	}

	container, err := db.NewContainer("product")

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	pk := azcosmos.NewPartitionKeyString("electronic")

	payload, err := json.Marshal(Item{
		ID:       "1",
		Name:     "Laptop",
		Category: "electronic",
	})

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	_, err = container.UpsertItem(ctx, pk, payload, nil)

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	// Read
	resp, err := container.ReadItem(ctx, pk, "1", nil)

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	log.Printf("Read Item: %v\n", resp.Value)

	var decodeItem Item

	err = json.Unmarshal(resp.Value, &decodeItem)

	if err != nil {
		log.Fatalf("%s\n", err)
	}

	log.Printf("Decode Item: %+v\n", decodeItem)

	// Query semua item pada partition key yang sama
	pager := container.NewQueryItemsPager("SELECT * FROM c", pk, nil)

	for pager.More() {
		page, err := pager.NextPage(ctx)

		if err != nil {
			log.Fatalf("%s\n", err)
		}

		for _, raw := range page.Items {
			log.Printf("Item: %s\n", raw)
		}
	}

	// Delete
	_, err = container.DeleteItem(ctx, pk, "1", nil)

	if err != nil {
		log.Fatalf("%s\n", err)
	}
}
