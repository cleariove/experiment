package ex001.dice;

import java.util.Random;

public class Dice
{
    private int num;
    public Dice()
    {

    }

    public void throwDice()
    {
        this.num = new Random().nextInt(6) + 1;
    }

    public int getNum()
    {
        return num;
    }

}
