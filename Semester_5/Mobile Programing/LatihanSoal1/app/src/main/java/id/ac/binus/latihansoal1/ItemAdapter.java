package id.ac.binus.latihansoal1;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class ItemAdapter extends RecyclerView.Adapter<ItemHolder> {

    // TODO: ADD VARIABLES 'CONTEXT' AND 'LIST'
    Context context;
    List<ItemData> listData = new ArrayList<ItemData>();
    // TODO: ADD CONSTRUCTOR USING GENERATE
    public ItemAdapter(Context context, List<ItemData> listData) {
        this.context = context;
        this.listData = listData;
    }

    // TODO: IMPLEMENT OVERRIDE METHODS
    @NonNull
    @Override
    public ItemHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ItemHolder(LayoutInflater.from(context).inflate(R.layout.item_views, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull ItemHolder holder, int position) {
        // TODO: ADD DATA DISPLAY CODE HERE
        holder.itemImage.setImageResource(listData.get(position).getItemImage());
        holder.itemCode.setText(listData.get(position).getItemCode());
        holder.itemName.setText(listData.get(position).getItemName());
        holder.itemDesc.setText(listData.get(position).getItemDesc());
        holder.itemAvailability.setText(listData.get(position).getItemAvailability());

        if (listData.get(position).getItemAvailability().equals("Available")) {
            holder.itemAvailability.setBackgroundColor(ContextCompat.getColor(context, R.color.green));
        } else if (listData.get(position).getItemAvailability().equals("Checked Out")) {
            holder.itemAvailability.setBackgroundColor(ContextCompat.getColor(context, R.color.red));
        }
    }

    @Override
    public int getItemCount() {
        // TODO: FIX THE ITEM COUNT
        return listData.size();
    }

}
