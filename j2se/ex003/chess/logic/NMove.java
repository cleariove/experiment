package ex003.chess.logic;

public class NMove implements Move
{

    public NMove()
    {
    }

    @Override
    public boolean move(int x,int y,int nextX,int nextY)
    {
        return (Math.abs(nextX - x) == 2 && Math.abs(nextY - y) == 1) ||
                (Math.abs(nextX - x) == 1 && Math.abs(nextY - y) == 2);
    }
}
