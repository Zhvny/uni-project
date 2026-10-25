package id.ac.binus.le01recyclerview;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    RecyclerView recyclerViewData;
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
        recyclerViewData = findViewById(R.id.recycleViewData);
        List<ItemData> listData = new ArrayList<ItemData>();
        listData.add(new ItemData(
                "Sepatu Satu",
                "Rp 1.000.000,00",
                "Sepatu Baru Nih Harga Terjangkau",
                R.drawable.shoes1
        ));
        listData.add(new ItemData(
                "Sepatu Dua",
                "Rp 2.000.000,00",
                "Sepatu Baru Nih Harga Lumayan Terjangkau",
                R.drawable.shoes2
        ));
        listData.add(new ItemData(
                "Sepatu Tiga",
                "Rp 3.000.000,00",
                "Sepatu Baru Nih Harga Cukup Terjangkau",
                R.drawable.shoes3
        ));
        listData.add(new ItemData(
                "Sepatu Empat",
                "Rp 4.000.000,00",
                "Sepatu Baru Nih Harga Tidak Terjangkau",
                R.drawable.shoes4
        ));

        recyclerViewData.setLayoutManager(new LinearLayoutManager(this));
        recyclerViewData.setAdapter(new ItemAdapter(this, listData));

        findViewById(R.id.btnPrevious).setOnClickListener(v -> {
            startActivity(new Intent(MainActivity.this, CelanaActivity.class));
        });
        findViewById(R.id.btnNext).setOnClickListener(v -> {
            startActivity(new Intent(MainActivity.this, BajuActivity.class));
        });
    }
}