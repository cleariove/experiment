package ex003.chess.logic;


public class QMove implements Move
{

    public QMove()
    {
    }

    @Override
    public boolean move(int x, int y, int nextX, int nextY)
    {
        int i = 1,j = 1;
        if(x > nextX)
            i = -1;
        if(y > nextY)
            j = -1;

        return (Math.abs(nextX - x) == Math.abs(nextY - y)) ||
                nextX - x == 0 || nextY - y == 0;
    }
}
