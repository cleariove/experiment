package ex003.chess.logic;

public class Chess
{
    private ChessPiece[][] chessPieces;//整个棋盘上棋子均表示出来，没棋子的位置置为null
    private String currentSide;
    private int x;
    private int y;//x,y表示当前选中的棋子

    public Chess()
    {
        x = 0;
        y = 0;
        currentSide = "W";
        chessPieces = new ChessPiece[8][8];
        chessPieces[4][0] = new ChessPiece(ChessType.BK,4,0);
        chessPieces[3][0] = new ChessPiece(ChessType.BQ,3,0);
        chessPieces[2][0] = new ChessPiece(ChessType.BB,2,0);
        chessPieces[5][0] = new ChessPiece(ChessType.BB,5,0);
        chessPieces[1][0] = new ChessPiece(ChessType.BN,1,0);
        chessPieces[6][0] = new ChessPiece(ChessType.BN,6,0);
        chessPieces[0][0] = new ChessPiece(ChessType.BR,0,0);
        chessPieces[7][0] = new ChessPiece(ChessType.BR,7,0);
        for(int i = 0;i < 8;i++)
            chessPieces[i][1] = new ChessPiece(ChessType.BP,i,1);
        chessPieces[4][7] = new ChessPiece(ChessType.WK,4,7);
        chessPieces[3][7] = new ChessPiece(ChessType.WQ,3,7);
        chessPieces[2][7] = new ChessPiece(ChessType.WB,2,7);
        chessPieces[5][7] = new ChessPiece(ChessType.WB,5,7);
        chessPieces[1][7] = new ChessPiece(ChessType.WN,1,7);
        chessPieces[6][7] = new ChessPiece(ChessType.WN,6,7);
        chessPieces[0][7] = new ChessPiece(ChessType.WR,0,7);
        chessPieces[7][7] = new ChessPiece(ChessType.WR,7,7);
        for(int i = 0;i < 8;i++)
            chessPieces[i][6] = new ChessPiece(ChessType.WP,i,6);
    }

    public void moveChess(int nextX,int nextY)
            //移动棋子
    {
        chessPieces[nextX][nextY] = chessPieces[x][y];
        chessPieces[x][y] = null;
        chessPieces[nextX][nextY].setX(nextX);
        chessPieces[nextX][nextY].setY(nextY);
    }

    public boolean moveOffSide(int endX,int endY)
            //判断是否越子
    {
        int i,j;
        //i,j分别代表x,y移动方向
        if(endX > x)
            i = 1;
        else
            i = -1;
        if(endY > y)
            j = 1;
        else
            j = -1;
        int startX = x;
        int startY = y;
        if (startX != endX)
            endX = endX - i;
        if (startY != endY)
            endY = endY - j;
        //只判断路径上是否有棋子，不管棋子起点和终点
        while (startX != endX|| startY != endY)
        {
            if (startX != endX)
                startX = startX + i;
            if (startY != endY)
                startY = startY + j;
            if (chessPieces[startX][startY] != null)
                return false;

        }
        return true;
    }

    public void selectChess(int x,int y)
    {
        setX(x);
        setY(y);
    }

    public boolean continueGame(int nextX,int nextY)
            //判断游戏是否继续
    {
        return chessPieces[nextX][nextY] == null ||
                !chessPieces[nextX][nextY].getType().name().matches("(BK|WK)");
    }

    public ChessPiece[][] getChessPieces()
    {
        return chessPieces;
    }

    public int getX()
    {
        return x;
    }

    public void setX(int x)
    {
        this.x = x;
    }

    public int getY()
    {
        return y;
    }

    public void setY(int y)
    {
        this.y = y;
    }

    public String getCurrentSide()
    {
        return currentSide;
    }

    public void setCurrentSide()
    {
        this.currentSide = (currentSide == "W" ? "B" : "W");
    }
}
