package main

import (
	"context"
	"encoding/json"
	"log/slog"

	"github.com/azure/azure-functions-golang-worker/sdk"
	"github.com/azure/azure-functions-golang-worker/sdk/bindings"
	"github.com/azure/azure-functions-golang-worker/worker"
)

type blobEventData struct {
	URL         string `json:"url"`
	API         string `json:"api"`
	ContentType string `json:"contentType"`
}

// HandleFileUpload: satu handler untuk BlobCreated dan BlobDeleted.
// Event Grid bisa mengirim event yang sama lebih dari sekali (retry),
// jadi handler wajib idempotent: hanya membaca metadata, tidak mengubah state.
func HandleFileUpload(ctx context.Context, event bindings.EventGridEvent) error {
	var data blobEventData
	if err := json.Unmarshal(event.Data, &data); err != nil {
		slog.ErrorContext(ctx, "failed to decode Event Grid event data", "error", err)
		return err
	}

	switch event.EventType {
	case "Microsoft.Storage.BlobCreated":
		slog.InfoContext(ctx, "new blob is uploaded",
			"blob_url", data.URL, "content_type", data.ContentType,
			"subject", event.Subject)
	case "Microsoft.Storage.BlobDeleted":
		slog.InfoContext(ctx, "blob is deleted",
			"blob_url", data.URL, "subject", event.Subject)
	default:
		slog.InfoContext(ctx, "unhandled Event Grid event",
			"event_type", event.EventType)
	}
	return nil
}

func main() {
	app := sdk.FunctionApp()
	app.EventGrid("HandleFileUpload", HandleFileUpload)
	worker.Start(app)
}
