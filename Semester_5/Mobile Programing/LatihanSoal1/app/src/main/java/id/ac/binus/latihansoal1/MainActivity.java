package id.ac.binus.latihansoal1;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Toolbar toolbar;
    RecyclerView rvItem;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        toolbar = findViewById(R.id.navMenu);
        setSupportActionBar(toolbar);

        rvItem = findViewById(R.id.rvItem);
        List<ItemData> listData = new ArrayList<ItemData>();

        // TODO: INSERT DATA INTO listData
        listData.add(new ItemData(
                "TOOL-001",
                "Drill",
                "For drilling.",
                "Available",
                R.drawable.tools1
        ));

        listData.add(new ItemData(
                "TOOL-002",
                "Crimping Tool",
                "For crimping.",
                "Checked Out",
                R.drawable.tools2
        ));

        listData.add(new ItemData(
                "TOOL-003",
                "Saw",
                "For sawing.",
                "Available",
                R.drawable.tools3
        ));

        listData.add(new ItemData(
                "TOOL-004",
                "Scrafier",
                "For scrafing.",
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

        // TODO: SETUP RECYCLER VIEW
        rvItem.setLayoutManager(new LinearLayoutManager(this));
        rvItem.setAdapter(new ItemAdapter(this, listData));
    }

    // TODO: GENERATE onCreateOptionsMenu

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.nav_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if (item.getItemId() == R.id.menuRentTools) {
            // TODO: HOOK TO CORRESPONDING PAGE
            Intent intent = new Intent(this, MainActivity.class);
            startActivity(intent);
        }

        else if (item.getItemId() == R.id.menuRentWorkers) {
            Intent intent = new Intent(this, WorkersActivity.class);
            startActivity(intent);
        }
        // TODO: SET UP OTHER MENUs
        return true;
    }
}