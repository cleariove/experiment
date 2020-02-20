package ex003.chess.logic;

public class RMove implements Move
{
    public RMove()
    {
    }

    @Override
    public boolean move(int x, int y, int nextX, int nextY)
    {
        return nextX - x == 0 || nextY - y == 0;
    }
}
