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

public class CelanaActivity extends AppCompatActivity {

    RecyclerView recyclerViewData;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_celana);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        recyclerViewData = findViewById(R.id.recycleViewData);
        List<ItemData> listData = new ArrayList<ItemData>();
        listData.add(new ItemData(
                "Celana Satu",
                "Rp 150.000,00",
                "Celana Baru Nih Harga Terjangkau",
                R.drawable.pants1
        ));
        listData.add(new ItemData(
                "Celana Dua",
                "Rp 250.000,00",
                "Celana Baru Nih Harga Lumayan Terjangkau",
                R.drawable.pants2
        ));
        listData.add(new ItemData(
                "Celana Tiga",
                "Rp 350.000,00",
                "Celana Baru Nih Harga Cukup Terjangkau",
                R.drawable.pants3
        ));
        listData.add(new ItemData(
                "Celana Empat",
                "Rp 450.000,00",
                "Celana Baru Nih Harga Tidak Terjangkau",
                R.drawable.pants4
        ));

        recyclerViewData.setLayoutManager(new LinearLayoutManager(this));
        recyclerViewData.setAdapter(new ItemAdapter(this, listData));

        findViewById(R.id.btnPrevious).setOnClickListener(v -> {
            startActivity(new Intent(CelanaActivity.this, BajuActivity.class));
        });
        findViewById(R.id.btnNext).setOnClickListener(v -> {
            startActivity(new Intent(CelanaActivity.this, MainActivity.class));
        });
    }
}
