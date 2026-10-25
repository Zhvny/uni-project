package id.ac.binus.le01recyclerview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class ItemAdapter extends RecyclerView.Adapter<ItemHolder> {
    Context context;
    List<ItemData> listData = new ArrayList<ItemData>();
    public ItemAdapter(Context context, List<ItemData> listData) {
        this.context = context;
        this.listData = listData;
    }

    @NonNull
    @Override
    public ItemHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ItemHolder(LayoutInflater.from(context).inflate(R.layout.item_view,parent,false));
    }

    @Override
    public void onBindViewHolder(@NonNull ItemHolder holder, int position) {
        holder.imageView.setImageResource(listData.get(position).getImage());
        holder.textNama.setText(listData.get(position).getNama());
        holder.textPrice.setText(listData.get(position).getPrice());
        holder.textDescription.setText(listData.get(position).getDesc());
    }

    @Override
    public int getItemCount() {
        return listData.size();
    }
}
