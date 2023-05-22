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

public class ViewerController {
    @FXML
    private TableView<RawMaterials> RawMaterialsTable;
    @FXML
    private TableColumn<RawMaterials, String> RawMaterialsNameColumn;
    @FXML
    private TableColumn<RawMaterials, String> RawMaterialsTypeColumn;
    @FXML
    private TableColumn<RawMaterials, Double> RawMaterialsAlcoholColumn;
    @FXML
    private TableColumn<RawMaterials, Double> RawMaterialsPriceColumn;
    @FXML
    private TableColumn<RawMaterials, Integer> RawMaterialsStockColumn;
    private RawMaterialsList RawMaterialsList;

    @FXML
    public void onBackButton(ActionEvent actionEvent) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/Main-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    public void onCommandeButton(ActionEvent actionEvent) throws IOException {
        //Create a new page
        Parent root = FXMLLoader.load(getClass().getResource("/com/marionesc/additivemanufacturinggesture/Order-page.fxml"));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) actionEvent.getSource()).getScene().getWindow();
        //Set the new page
        stage.setScene(scene);
        stage.show();
    }

    public void initialize() {
        RawMaterialsNameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        RawMaterialsTypeColumn.setCellValueFactory(new PropertyValueFactory<>("type"));
        RawMaterialsAlcoholColumn.setCellValueFactory(new PropertyValueFactory<>("alcohol"));
        RawMaterialsPriceColumn.setCellValueFactory(new PropertyValueFactory<>("price"));
        RawMaterialsStockColumn.setCellValueFactory(new PropertyValueFactory<>("stock"));
        //com.marionesc.additivemanufacturinggesture.Element.RawMaterialsList// Load data from CSV file
        RawMaterialsList RawMaterialsList = new RawMaterialsList();
        RawMaterialsList.loadFromCSV("RawMaterialsList.csv");

        // Convert the ArrayList to an ObservableList
        ObservableList<RawMaterials> beerData = FXCollections.observableArrayList(RawMaterialsList.getRawMaterialsList());

        // Set the ObservableList as the data source for the TableView
        RawMaterialsTable.setItems(beerData);
    }

}
