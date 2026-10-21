package main

import (
	"context"
	"fmt"
	"log/slog"
	"net/http"

	"github.com/azure/azure-functions-golang-worker/sdk"
	"github.com/azure/azure-functions-golang-worker/sdk/bindings"
	"github.com/azure/azure-functions-golang-worker/worker"
)

// Auth level "function": butuh ?code=<function key> atau header x-functions-key.
func helloFunction(w http.ResponseWriter, r *http.Request) {
	slog.InfoContext(r.Context(), "Function endpoint called",
		"method", r.Method, "path", r.URL.Path)

	name := r.URL.Query().Get("name")
	if name == "" {
		name = "world"
	}
	fmt.Fprintf(w, "Hello from function auth, %s!", name)
}

// Auth level "anonymous": bisa dipanggil tanpa key.
func helloAnonymous(w http.ResponseWriter, r *http.Request) {
	name := r.URL.Query().Get("name")
	if name == "" {
		name = "world"
	}
	fmt.Fprintf(w, "Hello from anonymous, %s!", name)
}

// Auth level "admin": butuh master key.
func helloAdmin(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "Hello from admin auth, master key accepted!")
}

// Timer trigger: NCRONTAB 6 kolom (detik menit jam tanggal bulan hari).
// 0 0 6 * * * = 06:00 UTC = 13:00 WIB.
func cronJob(ctx context.Context, timer bindings.TimerInfo) error {
	slog.InfoContext(ctx, "Cron job success",
		"next_schedule", timer.ScheduleStatus.Next)
	return nil
}

func main() {
	app := sdk.FunctionApp()

	app.HTTP("hello", helloFunction,
		sdk.WithMethods("GET", "POST"), sdk.WithAuth("function"))
	app.HTTP("hello2", helloAnonymous,
		sdk.WithMethods("GET", "POST"), sdk.WithAuth("anonymous"))
	app.HTTP("hello3", helloAdmin,
		sdk.WithMethods("GET", "POST"), sdk.WithAuth("admin"))
	app.Timer("cronJob", cronJob, sdk.WithSchedule("0 0 6 * * *"))

	worker.Start(app)
}
