package com.marionesc.additivemanufacturinggesture;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

public class HelloController {
    @FXML
    private ComboBox<String> comboBox;

    @FXML
    private void onClickNext(ActionEvent event) throws IOException {
        String choice = comboBox.getValue();
        if (choice == null) {
            // User has not selected a role, so do nothing
            return;
        }


        String resource = switch (choice) {
            case "Gestion de matières" -> "/com/marionesc/additivemanufacturinggesture/admin-page.fxml";
            case "Gestion du parc machine" -> "/com/marionesc/additivemanufacturinggesture/hello-view.fxml";
            default -> throw new IllegalArgumentException("Invalid role selected: " + choice);
        };
        //System.out.println("Loading resource: " + resource);
        Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource(resource)));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }
}

