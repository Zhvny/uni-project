package id.ac.binus.le01recyclerview;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class ItemHolder extends RecyclerView.ViewHolder {
    ImageView imageView;
    TextView textNama;
    TextView textPrice;
    TextView textDescription;
    public ItemHolder(@NonNull View itemView) {
        super(itemView);
        imageView = itemView.findViewById(R.id.imageData);
        textNama = itemView.findViewById(R.id.textNamaData);
        textPrice = itemView.findViewById(R.id.textPriceData);
        textDescription = itemView.findViewById(R.id.textDescriptionData);
    }
}
