package ex003.chess.logic;

public class KMove implements Move
{

    public KMove()
    {
    }

    @Override
    public boolean move(int x, int y, int nextX, int nextY)
    {
        return (Math.abs(nextX - x) <= 1 && Math.abs(nextY - y) <= 1);
    }
}
