package id.ac.binus.le01multipleactivities;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class ReplyActivity extends AppCompatActivity {


    EditText edtReply;
    Button btnReply;
    TextView balas_balas;

    Intent intent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_reply);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        edtReply = findViewById(R.id.edtReply);
        btnReply = findViewById(R.id.btnReply);
        balas_balas = findViewById(R.id.balas_balas);

        intent = getIntent();

        String message = intent.getStringExtra("message");
        if (message != null) {
            balas_balas.setText(message);
            edtReply.setText(message);
        }

        btnReply.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                intent = new Intent(ReplyActivity.this,MainActivity.class);
                intent.putExtra("message", edtReply.getText().toString());
                startActivity(intent);
            }
        });
    }
}