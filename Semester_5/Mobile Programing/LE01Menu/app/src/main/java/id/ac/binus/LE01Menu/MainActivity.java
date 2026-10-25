package id.ac.binus.LE01Menu;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Toolbar toolbar;
    List<ItemData> listData = new ArrayList<ItemData>();

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.nav_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        if(item.getItemId() == R.id.menuProfile) {
            startActivity(new Intent(this, ProfileActivity.class));
        } else if (item.getItemId() == R.id.menuSepatu) {
            filter("Sepatu");
        } else if (item.getItemId() == R.id.menuPakaian) {
            filter("Pakaian");
        } else if (item.getItemId() == R.id.menuKemeja) {
            filter("Pakaian");
        } else if (item.getItemId() == R.id.menuBawahan) {
            filterBottom();
        }
        return true;
    }

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

        RecyclerView rvItem;
        rvItem = findViewById(R.id.rvItem);
        rvItem.setLayoutManager(new androidx.recyclerview.widget.LinearLayoutManager(this));
        // listData field initialized

        listData.add(
                new ItemData(
                        "Sepatu 1",
                        "Rp 1.000.000",
                        "Sepatu murah",
                        R.drawable.shoes1

                ));
        listData.add(
                new ItemData(
                        "Sepatu 2",
                        "Rp 2.000.000",
                        "Sepatu lumayan murah",
                        R.drawable.shoes2

                ));
        listData.add(
                new ItemData(
                        "Sepatu 3",
                        "Rp 3.000.000",
                        "Sepatu agak murah",
                        R.drawable.shoes3

                ));
        listData.add(
                new ItemData(
                        "Sepatu 4",
                        "Rp 4.000.000",
                        "Sepatu ga terlalu murah",
                        R.drawable.shoes4

                ));
        listData.add(
                new ItemData(
                        "Sepatu 5",
                        "Rp 5.000.000",
                        "Sepatu ga murah",
                        R.drawable.shoes5

                ));
        listData.add(
                new ItemData(
                        "Pakaian 1",
                        "Rp 1.100.000",
                        "Pakaian murah",
                        R.drawable.cloth1

                ));
        listData.add(
                new ItemData(
                        "Pakaian 2",
                        "Rp 2.200.000",
                        "Pakaian lumayan murah",
                        R.drawable.cloth2

                ));
        listData.add(
                new ItemData(
                        "Pakaian 3",
                        "Rp 3.300.000",
                        "Pakaian agak murah",
                        R.drawable.cloth3

                ));
        listData.add(
                new ItemData(
                        "Pakaian 4",
                        "Rp 4.400.000",
                        "Pakaian ga terlalu murah",
                        R.drawable.cloth4

                ));
        listData.add(
                new ItemData(
                        "Pakaian 5",
                        "Rp 5.500.000",
                        "Pakaian ga murah",
                        R.drawable.cloth5

                ));
        listData.add(
                new ItemData(
                        "Celana 1",
                        "Rp 1.100.001",
                        "Celana murah",
                        R.drawable.bottom1

                ));
        listData.add(
                new ItemData(
                        "Celana 2",
                        "Rp 2.200.002",
                        "Celana lumayan murah",
                        R.drawable.bottom2

                ));
        listData.add(
                new ItemData(
                        "Celana 3",
                        "Rp 3.300.003",
                        "Celana agak murah",
                        R.drawable.bottom3

                ));
        listData.add(
                new ItemData(
                        "Rok 1",
                        "Rp 1.100.001",
                        "Rok ga terlalu murah",
                        R.drawable.bottom4

                ));
        listData.add(
                new ItemData(
                        "Rok 2",
                        "Rp 2.200.002",
                        "Rok ga murah",
                        R.drawable.bottom5

                ));

        rvItem.setAdapter(new ItemAdaptor(this, listData));
    }

    private void filter(String prefix) {
        List<ItemData> filtered = new ArrayList<>();
        for (ItemData d : listData) {
            if (d.getItemName().startsWith(prefix)) filtered.add(d);
        }
        RecyclerView rv = findViewById(R.id.rvItem);
        rv.setAdapter(new ItemAdaptor(this, filtered));
    }

    private void filterBottom() {
        List<ItemData> filtered = new ArrayList<>();
        for (ItemData d : listData) {
            if (d.getItemName().startsWith("Celana") || d.getItemName().startsWith("Rok")) filtered.add(d);
        }
        RecyclerView rv = findViewById(R.id.rvItem);
        rv.setAdapter(new ItemAdaptor(this, filtered));
    }
}
