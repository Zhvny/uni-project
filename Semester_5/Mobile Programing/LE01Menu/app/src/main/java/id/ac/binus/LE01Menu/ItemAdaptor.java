package id.ac.binus.LE01Menu;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class ItemAdaptor extends RecyclerView.Adapter<ItemHolder> {
    Context contect;
    List<ItemData> lsitData = new ArrayList<ItemData>();

    public ItemAdaptor(Context contect, List<ItemData> lsitData) {
        this.contect = contect;
        this.lsitData = lsitData;
    }

    @NonNull
    @Override
    public ItemHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ItemHolder(LayoutInflater.from(contect).inflate(R.layout.layout_view, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull ItemHolder holder, int position) {
        holder.itemImage.setImageResource(lsitData.get(position).getItemImage());
        holder.itemName.setText(lsitData.get(position).getItemName());
        holder.itemPrice.setText(lsitData.get(position).getItemPrice());
        holder.itemDesc.setText(lsitData.get(position).getItemDesc());
    }

    @Override
    public int getItemCount() {
        return lsitData.size();
    }
}
