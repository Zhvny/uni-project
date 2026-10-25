package id.ac.binus.le01recyclerview;

import android.content.Intent;
import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class BajuActivity extends AppCompatActivity {

    RecyclerView recyclerViewData;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_baju);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        recyclerViewData = findViewById(R.id.recycleViewData);
        List<ItemData> listData = new ArrayList<ItemData>();
        listData.add(new ItemData(
                "Baju Satu",
                "Rp 100.000,00",
                "Baju Baru Nih Harga Terjangkau",
                R.drawable.shirt1
        ));
        listData.add(new ItemData(
                "Baju Dua",
                "Rp 200.000,00",
                "Baju Baru Nih Harga Lumayan Terjangkau",
                R.drawable.shirt2
        ));
        listData.add(new ItemData(
                "Baju Tiga",
                "Rp 300.000,00",
                "Baju Baru Nih Harga Cukup Terjangkau",
                R.drawable.shirt3
        ));
        listData.add(new ItemData(
                "Baju Empat",
                "Rp 400.000,00",
                "Baju Baru Nih Harga Tidak Terjangkau",
                R.drawable.shirt4
        ));

        recyclerViewData.setLayoutManager(new LinearLayoutManager(this));
        recyclerViewData.setAdapter(new ItemAdapter(this, listData));

        findViewById(R.id.btnPrevious).setOnClickListener(v -> {
            startActivity(new Intent(BajuActivity.this, MainActivity.class));
        });
        findViewById(R.id.btnNext).setOnClickListener(v -> {
            startActivity(new Intent(BajuActivity.this, CelanaActivity.class));
        });
    }
}
