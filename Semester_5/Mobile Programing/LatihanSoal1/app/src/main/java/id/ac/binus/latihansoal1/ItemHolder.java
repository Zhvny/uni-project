package id.ac.binus.latihansoal1;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

// REMINDER: ItemHolder class should extend RecyclerView's ViewHolder
public class ItemHolder extends RecyclerView.ViewHolder{
    ImageView itemImage;
    TextView itemCode, itemName, itemDesc, itemAvailability;

    public ItemHolder(@NonNull View itemView) {
        super(itemView);
        itemImage.findViewById(R.id.itemImage);
        itemCode.findViewById(R.id.itemCode);
        itemName.findViewById(R.id.itemName);
        itemDesc.findViewById(R.id.itemDesc);
        itemAvailability.findViewById(R.id.itemAvailability);
    }

    // TODO: IMPLEMENT OVERRIDE METHODS

}
