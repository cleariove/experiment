package ex001.dice;

public enum GameStatus
{
    Win("Congratulation!You win!"),
    Lose("Sorry,you lose."),
    Goon("Game go on");
    private String gameStatus;
    private GameStatus(String gameStatus)
    {
        this.gameStatus = gameStatus;
    }

    public String toString()
    {
        return this.gameStatus;
    }
}
