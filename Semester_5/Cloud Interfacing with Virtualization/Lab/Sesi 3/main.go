package main

import (
	"context"
	"fmt"
	"os"

	"github.com/Azure/azure-sdk-for-go/sdk/storage/azblob"
	"github.com/joho/godotenv"
)

const (
	containerName = "tes"
	blobName      = "namafile.txt"
)

func main() {
	ctx := context.TODO()

	if err := godotenv.Load(); err != nil {
		fmt.Println("catatan: .env tidak ditemukan, memakai environment OS")
	}

	connectionString, ok := os.LookupEnv("CONNECTION_STRING")
	if !ok || connectionString == "" {
		fmt.Println("CONNECTION_STRING kosong; isi dulu di .env")
		return
	}

	client, err := azblob.NewClientFromConnectionString(connectionString, nil)
	if err != nil {
		fmt.Printf("gagal membuat client: %s\n", err)
		return
	}
	fmt.Printf("client: %s\n", client.URL())

	// Container harus ada sebelum upload.
	if _, err := client.CreateContainer(ctx, containerName, nil); err != nil {
		fmt.Printf("catatan: CreateContainer dilewati (%s)\n", err)
	}

	// Upload
	file, err := os.Open(blobName)
	if err != nil {
		fmt.Printf("gagal membuka %s: %s\n", blobName, err)
		return
	}
	defer file.Close()

	if _, err := client.UploadFile(ctx, containerName, blobName, file, nil); err != nil {
		fmt.Printf("gagal upload: %s\n", err)
		return
	}
	fmt.Println("upload selesai")

	// Download
	out, err := os.Create("read_test.txt")
	if err != nil {
		fmt.Printf("gagal membuat file lokal: %s\n", err)
		return
	}
	n, err := client.DownloadFile(ctx, containerName, blobName, out, nil)
	if err != nil {
		fmt.Printf("gagal download: %s\n", err)
		return
	}
	out.Close()
	fmt.Printf("Buffer Size: %d\n", n)

	// List (pager: hasil dibagi per halaman)
	pager := client.NewListBlobsFlatPager(containerName, nil)
	for pager.More() {
		page, err := pager.NextPage(ctx)
		if err != nil {
			fmt.Printf("gagal list: %s\n", err)
			return
		}
		for _, blob := range page.Segment.BlobItems {
			fmt.Println(*blob.Name)
		}
	}
}
