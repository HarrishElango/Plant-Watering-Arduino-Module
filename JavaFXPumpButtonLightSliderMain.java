package sample;

import javafx.beans.binding.Bindings;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import sample.SerialPortService;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Slider;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }


    @Override
    public void start(Stage primaryStage) {
        var sp = SerialPortService.getSerialPort("COM4");
        var outputStream = sp.getOutputStream();

        var pane = new BorderPane();

        var label = new Label();
        var button = new Button("Pump");

        var slider = new Slider();
        slider.setMin(0.0);
        slider.setMax(99.0);

        slider.valueProperty().addListener((observable, oldValue, newValue) ->{
            try{
                outputStream.write(newValue.byteValue());
            } catch(IOException e) {
                e.printStackTrace();

            }

        });
        button.setOnMouseReleased(value ->{
            try{
                outputStream.write(0);
            } catch(IOException e) {
                e.printStackTrace();

            }

        });
        button.setOnMousePressed(value ->{
            try{
                outputStream.write(255);
            } catch(IOException e) {
                e.printStackTrace();

            }

        });

        label.textProperty().bind(slider.valueProperty().asString());

        pane.setTop(button);
        pane.setBottom(label);
        pane.setCenter(slider);
        pane.setPadding(new Insets(0, 20, 0, 20));

        var scene = new Scene(pane, 400, 200);

        primaryStage.setScene(scene);
        primaryStage.show();
    }

}
