package ex003.chess.logic;

public class BMove implements Move
{

    public BMove()
    {
    }

    @Override
    public boolean move(int x, int y, int nextX, int nextY)
    {
        return (Math.abs(nextX - x) == Math.abs(nextY - y)) && x != nextX;
    }
}
