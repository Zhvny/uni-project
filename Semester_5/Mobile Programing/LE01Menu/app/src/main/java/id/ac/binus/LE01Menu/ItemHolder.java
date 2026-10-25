package id.ac.binus.LE01Menu;

import static id.ac.binus.LE01Menu.R.*;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class ItemHolder extends RecyclerView.ViewHolder {
    ImageView itemImage;
    TextView itemName, itemPrice, itemDesc;

    public ItemHolder(@NonNull View itemView) {
        super(itemView);
        itemImage = itemView.findViewById(R.id.itemImage);
        itemName = itemView.findViewById(R.id.itemName);
        itemPrice = itemView.findViewById(R.id.itemPrice);
        itemDesc = itemView.findViewById(R.id.itemDesc);
    }
}
