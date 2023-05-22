package com.marionesc.additivemanufacturinggesture.Controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;

import com.marionesc.additivemanufacturinggesture.Element.RawMaterialsList;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;

/** **/
public class RawMaterialsGesture {
    //Import the text fields from the fxml file and the combo box
    // -- RawMaterials(String name, String printType, String color, int stock, double price, String commentary)
    @FXML
    private TextField rw_name;

    private ComboBox<String> rw_printType;
    @FXML
    private TextField rw_color;
    @FXML
    private TextField rw_stock;
    @FXML
    private TextField rw_price;
    @FXML
    private TextField rw_commentary;

    /** **/
    public void onClickSave(ActionEvent actionEvent) throws IOException {
        //Get the values from the text fields and the combo box
        String name         = rw_name.getText();
        String printType    = rw_printType.getValue();
        String color        = rw_color.getText();
        int stock           = Integer.parseInt(rw_stock.getText());
        double price        = Double.parseDouble(rw_price.getText());
        String commentary   = rw_commentary.getText();

        //Create a new beer with the values
        RawMaterialsList RawMaterialsList = new RawMaterialsList();
        RawMaterialsList.loadFromCSV("RawMaterialsList.csv");
        RawMaterialsList.addRawMaterials(name, printType, color, stock, price, commentary);
        RawMaterialsList.saveToCSV("RawMaterialsList.csv");

        //Go back to the previous page
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/Admin-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();

    }
    @FXML
    public void onClickBack(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/Admin-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }
}
