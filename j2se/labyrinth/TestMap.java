package labyrinth;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class TestMap extends Application
{
    public static void main(String... args)
    {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage)
    {
        MapView mapView = new MapView();
        mapView.builderMap();
        Scene scene = new Scene(mapView,1000,1000);
        stage.setScene(scene);
        stage.show();
    }
}
