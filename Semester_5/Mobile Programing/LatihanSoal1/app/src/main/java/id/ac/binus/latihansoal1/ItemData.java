package id.ac.binus.latihansoal1;

public class ItemData {
    private String itemCode, itemName, itemDesc, itemAvailability;
    private int itemImage;

    public ItemData(String itemCode, String itemName, String itemDesc, String itemAvailability, int itemImage) {
        this.itemCode = itemCode;
        this.itemName = itemName;
        this.itemDesc = itemDesc;
        this.itemAvailability = itemAvailability;
        this.itemImage = itemImage;
    }

    public String getItemCode() {
        return itemCode;
    }

    public String getItemName() {
        return itemName;
    }

    public String getItemDesc() {
        return itemDesc;
    }

    public String getItemAvailability() {
        return itemAvailability;
    }

    public int getItemImage() {
        return itemImage;
    }
}
