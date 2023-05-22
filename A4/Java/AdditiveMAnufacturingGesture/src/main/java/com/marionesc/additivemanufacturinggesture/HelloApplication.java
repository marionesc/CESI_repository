/**
 * PROJET JAVA : Interface de gstion de stock pour impression 3D
 *
 * Projet realise dans le cadre d'un projet de cours en A4 au CESI-Toulouse, filière S3E
 *
 * @author marionesc
 * @github marionesc/CESI_repository/A4/Java/AdditiveManufacturingGesture
 *
 * all rights reserved @marionesc 2023
 */

package com.marionesc.additivemanufacturinggesture;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setTitle("Gestion De stock de Matière première pour la FA");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}