package ex003.chess.logic;

public class PMove implements Move
{

    public PMove()
    {
    }

    @Override
    public boolean move(int x, int y, int nextX, int nextY)
    {
            return nextX == x && Math.abs(nextY - y) == 1;
    }
}
