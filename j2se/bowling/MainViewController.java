package bowling;


import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class MainViewController {

    @FXML
    private Button single;

    public void goToSingleMatch(){
        try {
            //一定需要使用try-catch，不然编译器不会让你过的，Trust me!
            Parent anotherRoot = FXMLLoader.load(getClass().getResource("singleMatch.fxml"));
            Stage anotherStage = new Stage();
            anotherStage.setTitle("Another Window Triggered by Clicking");
            anotherStage.setScene(new Scene(anotherRoot, 600, 400));
            anotherStage.show();
        } catch (Exception e){
            e.printStackTrace();
        }

    }


}

