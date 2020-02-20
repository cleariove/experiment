package ex003.chess.controllers;

import ex003.chess.logic.Chess;
import ex003.chess.views.ChessPane;
import ex003.chess.logic.ChessPiece;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;

public class MoveAction implements EventHandler<MouseEvent>
{
    private ChessPane chessPane;
    private Chess chess;

    public MoveAction()
    {

    }

    public MoveAction(ChessPane chessPane, Chess chess)
    {
        this.chessPane = chessPane;
        this.chess = chess;
    }

    @Override
    public void handle(MouseEvent e)
    {
        int x = (int)(e.getX() / 80);
        int y = (int)(e.getY() / 80);
        ChessPiece destination = chess.getChessPieces()[x][y];//目的地棋子
        ChessPiece selectChess = chess.getChessPieces()[chess.getX()][chess.getY()];//当前选中的棋子
        if(destination != null &&
           destination.getType().getSide().equals(chess.getCurrentSide())
           )
        //选择要移动的棋子,目的地要有棋子且目的地为己方棋子
        {
            chessPane.selectChess(chess.getX() , chess.getY() , Color.YELLOWGREEN);
            chess.selectChess(x,y);
            chessPane.selectChess(x , y , Color.RED);
        }
        else if((destination == null || (!destination.getType().getSide().equals(chess.getCurrentSide()))) &&
                selectChess.getType().getSide().equals(chess.getCurrentSide()))
        //鼠标点击位置为空或为对方棋子且当前选中了己方棋子可以移动棋子
        {
            if(selectChess.getType().name().matches("(BN|WN)") && selectChess.move(x,y))
            //如果棋子为马则只要确保符合移动规则即可移动或者吃子
                this.moveChess(x,y);
            else if(chess.moveOffSide(x,y) && selectChess.move(x,y))
            //不是马的话则要确保没有出现越子且符合移动规则才可以吃子
                this.moveChess(x,y);
        }
    }

    public void moveChess(int x,int y)
    {
        if(chess.continueGame(x,y))
        //如果这此移动之后游戏仍旧继续的话则移动完之后换边
        {
            chessPane.moveChess(x, y);
            chess.moveChess(x, y);
            chess.selectChess(x, y);
            chess.setCurrentSide();
        }
        else
            //移动完之后就弹框选择是否继续游戏
        {
            chessPane.moveChess(x, y);
            chess.moveChess(x, y);
            chess.selectChess(x, y);
            chessPane.gameOver();
        }
    }
}
