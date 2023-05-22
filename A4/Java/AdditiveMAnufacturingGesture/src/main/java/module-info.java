module com.marionesc.additivemanufacturinggesture {
    requires javafx.controls;
    requires javafx.fxml;
            
                            
    opens com.marionesc.additivemanufacturinggesture to javafx.fxml;
    exports com.marionesc.additivemanufacturinggesture;
    exports com.marionesc.additivemanufacturinggesture.Element;
    opens com.marionesc.additivemanufacturinggesture.Element to javafx.fxml;
    exports com.marionesc.additivemanufacturinggesture.Controller;
    opens com.marionesc.additivemanufacturinggesture.Controller to javafx.fxml;
}