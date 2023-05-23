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
    private ComboBox<String> comboBoxRight;

    @FXML
    private ComboBox<String> comboBoxGesture;

    @FXML
    private void onClickNext(ActionEvent event) throws IOException {
        /*** CODE POUR LE CHOIX DES DROITS ***/
        String choiceRight = comboBoxRight.getValue();
        if (choiceRight == null) {
            return;
        }

        /*** CODE POUR LE CHOIX DU MENU ***/
        String choiceGesture = comboBoxGesture.getValue();
        if (choiceGesture == null) {
            return;
        }


        String resource;
        if (choiceRight.equals("Fabrication")) {
            /** CAS -->  SERVICE FA + STOCK **/
            if (choiceGesture.equals("Gestion des matieres")) {
                resource = "/com/marionesc/additivemanufacturinggesture/RMadmin-page.fxml";
            }

            /** CAS -->  SERVICE FA + MACHINE **/
            else if (choiceGesture.equals("Gestion du parc machine")) {
                //resource = "/com/marionesc/additivemanufacturinggesture/hello-view.fxml";
                System.out.println("Code non fonctionel pour le moment, oups");
                return;
            } else {
                throw new IllegalArgumentException("Invalid gesture selected: " + choiceGesture);
            }

        } else if (choiceRight.equals("Logistique")) {

            /** CAS -->  SERVICE LOG + STOCK **/
            if (choiceGesture.equals("Gestion des matieres")) {
                resource = "/com/marionesc/additivemanufacturinggesture/RMviewer-page.fxml";
            }

            /** CAS -->  SERVICE FA + MACHINE **/
            else if (choiceGesture.equals("Gestion du parc machine")) {
                //resource = "/com/marionesc/additivemanufacturinggesture/hello-view.fxml";
                System.out.println("Code non fonctionel pour le moment, oups");
                return;
            } else {
                throw new IllegalArgumentException("Invalid gesture selected: " + choiceGesture);
            }
        } else {
            throw new IllegalArgumentException("Invalid right selected: " + choiceRight);
        }

        //System.out.println("Loading resource: " + resource);
        Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource(resource)));
        Scene scene = new Scene(root);
        Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }
}