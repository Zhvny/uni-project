package id.ac.binus.latihansoal1;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class WorkersActivity extends AppCompatActivity {

    Toolbar toolbar;

    RecyclerView rvItem;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        WindowCompat.enableEdgeToEdge(getWindow());
        setContentView(R.layout.activity_workers);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        toolbar = findViewById(R.id.navMenu);
        setSupportActionBar(toolbar);

        rvItem = findViewById(R.id.rvItem);
        List<ItemData> listData = new ArrayList<ItemData>();

//        DATA HERE
        listData.add(new ItemData(
                "WRK-001",
                "Nga 1",
                "Use yellow hat.",
                "Checked Out",
                R.drawable.worker1
        ));

        listData.add(new ItemData(
                "WRK-002",
                "Wht 1",
                "Use yellow hat.",
                "Available",
                R.drawable.worker2
        ));

        listData.add(new ItemData(
                "WRK-003",
                "Nga 2",
                "Use yellow hat with smiling face.",
                "Checked Out",
                R.drawable.worker3
        ));

        listData.add(new ItemData(
                "WRK-004",
                "Wht 2",
                "Bro carrying .",
                "Checked Out",
                R.drawable.tools4
        ));

        listData.add(new ItemData(
                "TOOL-005",
                "Nailer",
                "For nailing.",
                "Available",
                R.drawable.tools5
        ));

        rvItem.setAdapter(new ItemAdapter(this, listData));
        rvItem.setLayoutManager(new LinearLayoutManager(this));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.nav_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.menuRentTools) {
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        } else if (item.getItemId() == R.id.menuRentWorkers) {
            Intent intent = new Intent(this, WorkersActivity.class);
            startActivity(intent);
        }
        return true;
    }
}