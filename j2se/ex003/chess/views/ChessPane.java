package ex003.chess.views;

import ex003.chess.controllers.MoveAction;
import ex003.chess.logic.Chess;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.image.Image;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;

import java.util.Optional;


public class ChessPane extends BorderPane
{
    private Canvas canvas;
    private GraphicsContext gc;
    private Chess chess;
    private Image[] images = new Image[12];

    public ChessPane()
    {
        chess = new Chess();
        canvas = new Canvas(640,640);
        gc = canvas.getGraphicsContext2D();
        images[0] = new Image("ex003/chess/images/blackKing.png");
        images[1] = new Image("ex003/chess/images/blackQueen.png");
        images[2] = new Image("ex003/chess/images/blackBishop.png");
        images[3] = new Image("ex003/chess/images/blackKnight.png");
        images[4] = new Image("ex003/chess/images/blackRook.png");
        images[5] = new Image("ex003/chess/images/blackPawn.png");
        images[6] = new Image("ex003/chess/images/whiteKing.png");
        images[7] = new Image("ex003/chess/images/whiteQueen.png");
        images[8] = new Image("ex003/chess/images/whiteBishop.png");
        images[9] = new Image("ex003/chess/images/whiteKnight.png");
        images[10] = new Image("ex003/chess/images/whiteRook.png");
        images[11] = new Image("ex003/chess/images/whitePawn.png");
    }

    public void startGame()
    {
        canvas.setOnMouseClicked(new MoveAction(this,this.chess));
    }

    public void drawPane()
    {
        gc.clearRect(0,0,640,640);
        for(int i = 0;i < 8;i++)
            for(int j = 0;j < 8;j++)
            {
                if((i+j) % 2 == 0)
                    gc.setFill(Color.YELLOW);
                else
                    gc.setFill(Color.YELLOWGREEN);
                gc.fillRect(i * 80,j * 80,(i + 1) * 80,(j + 1) * 80);
            }
        gc.setStroke(Color.BLACK);
        gc.strokeRect(0,0,640,640);
        gc.drawImage(images[0],320,0,80,75);
        gc.drawImage(images[1],240,0,80,75);
        gc.drawImage(images[2],160,0,80,75);
        gc.drawImage(images[2],400,0,80,75);
        gc.drawImage(images[3],80,0,80,75);
        gc.drawImage(images[3],480,0,80,75);
        gc.drawImage(images[4],0,0,80,75);
        gc.drawImage(images[4],560,0,80,75);
        for(int i = 0;i < 8;i++)
            gc.drawImage(images[5],80 * i,80,80,75);
        gc.drawImage(images[6],320,560,80,75);
        gc.drawImage(images[7],240,560,80,75);
        gc.drawImage(images[8],160,560,80,75);
        gc.drawImage(images[8],400,560,80,75);
        gc.drawImage(images[9],80,560,80,75);
        gc.drawImage(images[9],480,560,80,75);
        gc.drawImage(images[10],0,560,80,75);
        gc.drawImage(images[10],560,560,80,75);
        for(int i = 0;i < 8;i++)
            gc.drawImage(images[11],80 * i,480,80,75);
        this.setCenter(canvas);
    }

    public void moveChess(int x,int y)
    {
        if((x + y) % 2 == 0)
            gc.setFill(Color.YELLOW);
        else
            gc.setFill(Color.YELLOWGREEN);
        gc.clearRect(x * 80, y * 80,80,80);
        gc.fillRect(x * 80, y * 80,80,80);
        gc.drawImage(getImage(chess.getX(),chess.getY()),x * 80,y * 80,80,75);
        gc.clearRect(chess.getX() * 80, chess.getY() * 80,80,80);
        if((chess.getX() + chess.getY()) % 2 == 0)
            gc.setFill(Color.YELLOW);
        else
            gc.setFill(Color.YELLOWGREEN);
        gc.fillRect(chess.getX() * 80, chess.getY() * 80 ,80,80);
    }

    public Image getImage(int x,int y)
    {
        switch (chess.getChessPieces()[x][y].getType())
        {
            case BK:
                return images[0];
            case WK:
                return images[6];
            case BQ:
                return images[1];
            case WQ:
                return images[7];
            case BB:
                return images[2];
            case WB:
                return images[8];
            case BN:
                return images[3];
            case WN:
                return images[9];
            case BR:
                return images[4];
            case WR:
                return images[10];
            case BP:
                return images[5];
            case WP:
                return images[11];
        }
        return null;
    }

    public void selectChess(int x,int y,Color color)
    {
        gc.setStroke(color);
        gc.strokeRect(x * 80,y * 80,79,79);
    }

    public void gameOver()
    {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION,"再来一局？");
        alert.setTitle("游戏结束");
        alert.setHeaderText("恭喜"+chess.getCurrentSide()+"方获胜！");
        Optional<ButtonType> result = alert.showAndWait();
        if(result.get() == ButtonType.OK)
        {
            this.chess = new Chess();
            this.drawPane();
            this.startGame();
        }
        else
        {
            Canvas canvas1 = this.canvas;
            this.setCenter(canvas1);
        }
    }
}
