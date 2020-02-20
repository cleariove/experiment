package ex001.dice;

public class Start
{
    public static void main(String[] args)
    {
        Dice[] dice = new Dice[2];
        dice[0] = new Dice();
        dice[1] = new Dice();
        GameStatus gameStatus = GameStatus.Goon;
        dice[0].throwDice();
        dice[1].throwDice();
        int sum = dice[0].getNum() + dice[1].getNum();
        System.out.printf("第一个骰子的点数为:%d,第二个骰子的点数为:%d,和为:%d\n",dice[0].getNum(),dice[1].getNum(),sum);
        if(sum == 7 || sum == 11)
            gameStatus = GameStatus.Win;
        else if(sum == 2 || sum == 3 || sum == 12)
            gameStatus = GameStatus.Lose;
        else
        {
            while(gameStatus.name().equals("Goon"))
            {
                dice[0].throwDice();
                dice[1].throwDice();
                if(dice[0].getNum() + dice[1].getNum() == sum)
                {
                    gameStatus = GameStatus.Win;
                    sum = dice[0].getNum() + dice[1].getNum();
                }
                else if(dice[0].getNum() + dice[1].getNum() == 7)
                {
                    gameStatus = GameStatus.Lose;
                    sum = 7;
                }
                else
                    sum = dice[0].getNum() + dice[1].getNum();
                System.out.printf("第一个骰子的点数为:%d,第二个骰子的点数为:%d,和为:%d\n",dice[0].getNum(),dice[1].getNum(),sum);
            }
        }
        System.out.println(gameStatus.toString());
    }

}
