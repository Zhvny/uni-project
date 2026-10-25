package id.ac.binus.le01layoutview;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    private EditText edtInput1;
    private EditText edtOperator;
    private EditText edtInput2;
    private TextView hasil;
    private EditText activeInput;


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

        edtInput1 = findViewById(R.id.edtInput1);
        edtOperator = findViewById(R.id.edtOperator);
        edtInput2 = findViewById(R.id.edtInput2);
        hasil = findViewById(R.id.hasil);

        // Buat ga muncuh keyboard
//        edtInput1.setShowSoftInputOnFocus(false);
//        edtInput2.setShowSoftInputOnFocus(false);
//        edtOperator.setShowSoftInputOnFocus(false);

        activeInput = edtInput1;
        edtInput1.setOnFocusChangeListener((v, hasFocus) -> {
            if (hasFocus) activeInput = edtInput1;
        });
        edtInput2.setOnFocusChangeListener((v, hasFocus) -> {
            if (hasFocus) activeInput = edtInput2;
        });

        int[] numberButtonIds = {
                R.id.btn0, R.id.btn1, R.id.btn2, R.id.btn3, R.id.btn4,
                R.id.btn5, R.id.btn6, R.id.btn7, R.id.btn8, R.id.btn9
        };
        for (int id : numberButtonIds) {
            findViewById(id).setOnClickListener(v -> {
                String digit = ((android.widget.Button) v).getText().toString();
                appendDigit(digit);
            });
        }

        findViewById(R.id.btnPlus).setOnClickListener(v -> setOperator("+"));
        findViewById(R.id.btnMinus).setOnClickListener(v -> setOperator("-"));
        findViewById(R.id.btnMultiple).setOnClickListener(v -> setOperator("*"));
        findViewById(R.id.btnDevide).setOnClickListener(v -> setOperator("/"));
        findViewById(R.id.btnEqual).setOnClickListener(v -> calculate());
    }

    private void appendDigit(String digit) {
        if (activeInput == null) {
            activeInput = edtInput1;
        }
        String current = activeInput.getText().toString();
        activeInput.setText(current + digit);
        activeInput.setSelection(activeInput.getText().length());
    }

    private void setOperator(String operator) {
        edtOperator.setText(operator);
        activeInput = edtInput2;
        edtInput2.requestFocus();
        edtInput2.setSelection(edtInput2.getText().length());
    }

    private void calculate() {
        String firstText = edtInput1.getText().toString().trim();
        String secondText = edtInput2.getText().toString().trim();
        String operator = edtOperator.getText().toString().trim();

        if (firstText.isEmpty() || secondText.isEmpty()) {
            Toast.makeText(this, "Isi angka ke-1 dan angka ke-2 dulu", Toast.LENGTH_SHORT).show();
            return;
        }

        double first;
        double second;
        try {
            first = Double.parseDouble(firstText);
            second = Double.parseDouble(secondText);
        } catch (NumberFormatException e) {
            Toast.makeText(this, "Angka tidak valid", Toast.LENGTH_SHORT).show();
            return;
        }

        double result;
        switch (operator) {
            case "+":
                result = first + second;
                break;
            case "-":
                result = first - second;
                break;
            case "*":
                result = first * second;
                break;
            case "/":
                if (second == 0) {
                    Toast.makeText(this, "Tidak bisa dibagi nol", Toast.LENGTH_SHORT).show();
                    return;
                }
                result = first / second;
                break;
            default:
                Toast.makeText(this, "Operator harus +, -, *, atau /.", Toast.LENGTH_SHORT).show();
                return;
        }

        hasil.setText(formatNumber(result));
    }

    private String formatNumber(double value) {
        if (!Double.isInfinite(value) && value == Math.floor(value)) {
            return String.valueOf((long) value);
        }
        return String.valueOf(value);
    }
}
