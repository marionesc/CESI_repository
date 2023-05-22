package com.marionesc.additivemanufacturinggesture.Controller;


import com.marionesc.additivemanufacturinggesture.Element.RawMaterials;
import com.marionesc.additivemanufacturinggesture.Element.RawMaterialsList;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import java.io.IOException;


public class AdminPageController {
    @FXML
    private TableView<RawMaterials> RawMaterialsList;
    @FXML
    private TableColumn<RawMaterials, String> RawMaterialsNameColumn;
    @FXML
    private TableColumn<RawMaterials, String> RawMaterialsPrintTypeColumn;
    @FXML
    private TableColumn<RawMaterials, String> RawMaterialsColorColumn;
    @FXML
    private TableColumn<RawMaterials, Double> RawMaterialsStockColumn;
    @FXML
    private TableColumn<RawMaterials, Double> RawMaterialsPriceColumn;
    @FXML
    private TableColumn<RawMaterials, Integer> RawMaterialsCommentaryColumn;

    /**
     * FONCTION POUR LE BOUTON D'AJOUT
     */
    @FXML
    public void onAddButton(ActionEvent actionEvent) throws IOException {
        //Open a new page to add a new beer :
        /*Parent root = FXMLLoader.load(getClass().getResource("BeerAdd-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();*/
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/RawMaterialsAdd-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();

    }

    /**
     * FONCTION POUR LE BOUTON DE RETOUR AU MENU PRINCIPAL
     */
    @FXML
    public void onBackButton(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/Hello-view.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }

    /**
     * FONCTION POUR LE BOUTON DE MISE A JOUR
     */
    @FXML
    public void onMajButton(ActionEvent event) {
        initialize();
    }


    public void initialize() {
        RawMaterialsNameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        RawMaterialsPrintTypeColumn.setCellValueFactory(new PropertyValueFactory<>("printType"));
        RawMaterialsColorColumn.setCellValueFactory(new PropertyValueFactory<>("color"));
        RawMaterialsStockColumn.setCellValueFactory(new PropertyValueFactory<>("stock"));
        RawMaterialsPriceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        RawMaterialsCommentaryColumn.setCellValueFactory(new PropertyValueFactory<>("commentary"));

        // Load data from CSV file
        RawMaterialsList rawmaterialslist = new RawMaterialsList();
        System.out.println("ok ? ");
        rawmaterialslist.loadFromCSV("rawmaterialslist.csv");

        // Convert the ArrayList to an ObservableList
        ObservableList<RawMaterials> RawMaterialsData = FXCollections.observableArrayList(rawmaterialslist.getRawMaterialsList());

        // Set the ObservableList as the data source for the TableView
        RawMaterialsList.setItems(RawMaterialsData);

    }

    @FXML
    /**
     * FONCTION POUR LE BOUTON DE SUPPRESSION
     */
    public void onSupButton(ActionEvent event) {
        // Get the selected item
        RawMaterials selectedRawMaterials = RawMaterialsList.getSelectionModel().getSelectedItem();

        if (selectedRawMaterials != null) {
            // Load data from CSV file
            RawMaterialsList rawMaterialsList = new RawMaterialsList();
            rawMaterialsList.loadFromCSV("rawmaterialslist.csv");

            // Remove the selected item from the ArrayList
            rawMaterialsList.getRawMaterialsList().remove(selectedRawMaterials);

            // Save the ArrayList to the CSV file
            rawMaterialsList.saveToCSV("rawmaterialslist.csv");

            // Refresh the TableView
            RawMaterialsList.getItems().remove(selectedRawMaterials);
        }
    }

}

