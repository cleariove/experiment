package ex003.chess.logic;

public class ChessPiece
{
    private ChessType type;

    private int x;

    private int y;

    private Move move;

    private int times = 1;

    public ChessPiece()
    {
    }

    public ChessPiece(ChessType type,int x,int y)
    {
        this.type = type;
        this.x = x;
        this.y = y;
        switch (type)
        {
            case BK:

            case WK:
                move = new KMove();
                break;
            case WQ:

            case BQ:
                move = new QMove();
                break;
            case BB:

            case WB:
                move = new BMove();
                break;
            case BR:

            case WR:
                move = new RMove();
                break;
            case BP:

            case WP:
                move = new PMove();
                break;
            case BN:

            case WN:
                move = new NMove();
                break;
        }
    }

    public boolean move(int nextX,int nextY)
    {
        if(times == 1 && (type.name().equals("WP") || type.name().equals("BP")) )
        {
            if(Math.abs(nextY - y) <= 2 && nextX == x)
            {
                times = 2;
                return true;
            }
            else
                return false;
        }
        else
            return move.move(x,y,nextX,nextY);
    }


    public ChessType getType()
    {
        return type;
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
}
