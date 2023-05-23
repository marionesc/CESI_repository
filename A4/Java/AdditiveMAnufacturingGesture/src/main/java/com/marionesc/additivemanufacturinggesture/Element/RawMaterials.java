package com.marionesc.additivemanufacturinggesture.Element;

public class RawMaterials {
    private String name;
    private String color;
    private String printType;
    public double stock;
    public double price;

    public String commentary;


    public RawMaterials(String name, String printType, String color, double stock, double price, String commentary) {
        this.name = name;
        this.color = color;
        this.printType = printType;
        this.stock = stock;
        this.price = price;
        this.commentary = commentary;
    }

    /*** FONCTION SPE AU NOM ***/
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    /*** FONCTION SPE AU COULEUR***/
    public String getColor() {
        return color;
    }

    public void setAlcohol(String Color) {
        this.color = color;
    }

    /*** FONCTION SPE AU TYPE D'IMPRESSION***/
    public String getPrintType() {
        return printType;
    }

    public void setPrice(String printType) {
        this.printType = printType;
    }

    /*** FONCTION SPE AU STOCK ***/
    public double getStock() {
        return stock;
    }

    public void setStock(double stock) {
        this.stock = stock;
    }

    /*** FONCTION SPE AU STOCK ***/
    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    /*** FONCTION SPE AU COMMENTAIRES ***/
    public String getCommentary() {
        return commentary;
    }

    public void setCommentary(String commentary) {
        this.commentary = commentary;
    }

    public String toCSVString() {
        StringBuilder sb = new StringBuilder();

        // Concaténer les valeurs des attributs avec des virgules
        sb.append(name).append(",");
        sb.append(color).append(",");
        sb.append(printType).append(",");
        sb.append(stock).append(",");
        sb.append(price).append(",");
        sb.append(commentary).append(",");


        // Retourner la chaîne CSV
        return sb.toString();
    }

}