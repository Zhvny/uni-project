package id.ac.binus.latihansoal1;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class UploadActivity extends AppCompatActivity {

    Toolbar toolbar;
    Button btnUpload;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_upload);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        // TODO: DECLARE TOOLBAR & SETSUPPORTACTIONBAR
        toolbar = findViewById(R.id.navMenu);
        setSupportActionBar(toolbar);

        // TODO: MAKE BUTTON REDIRECT TO MAINACTIVITY
        btnUpload = findViewById(R.id.btnUpload);
        btnUpload.setOnClickListener(v -> {
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        });
    }

    // TODO: SETUP TOOLBAR
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.nav_menu, parent, false);
        return true;
    }


    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.menuRentTools) {
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        } else if (item.getItemId() == R.id.menuRentWorkers) {
            Intent intent = new Intent(this, WorkersActivity.class);
        }
        return true;
    }
}