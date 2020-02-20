package ex003.chess;

import ex003.chess.views.ChessPane;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Test extends Application
{

    public static void main(String[] args)
    {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage)
    {
        ChessPane chessPane;
        chessPane = new ChessPane();
        Scene scene = new Scene(chessPane, 1000, 800);
        chessPane.drawPane();
        chessPane.startGame();
        primaryStage.setTitle("国际象棋");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
