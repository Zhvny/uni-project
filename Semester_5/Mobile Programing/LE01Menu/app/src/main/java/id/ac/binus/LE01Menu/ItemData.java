package id.ac.binus.LE01Menu;

public class ItemData {
    private String itemName, itemPrice, itemDesc;
    private int itemImage;

    public ItemData(String itemName, String itemPrice, String itemDesc, int itemImage) {
        this.itemName = itemName;
        this.itemPrice = itemPrice;
        this.itemDesc = itemDesc;
        this.itemImage = itemImage;
    }

    public String getItemName() {
        return itemName;
    }

    public String getItemPrice() {
        return itemPrice;
    }

    public String getItemDesc() {
        return itemDesc;
    }

    public int getItemImage() {
        return itemImage;
    }
}
