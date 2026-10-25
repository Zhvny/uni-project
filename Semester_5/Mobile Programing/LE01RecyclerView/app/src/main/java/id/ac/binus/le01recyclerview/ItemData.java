package id.ac.binus.le01recyclerview;

public class ItemData {
    private String nama;
    private String price;
    private String desc;
    private int image;

    public ItemData(String nama, String price, String desc, int image) {
        this.nama = nama;
        this.price = price;
        this.desc = desc;
        this.image = image;
    }

    public String getNama() {
        return nama;
    }

    public String getPrice() {
        return price;
    }

    public String getDesc() {
        return desc;
    }

    public int getImage() {
        return image;
    }
}
