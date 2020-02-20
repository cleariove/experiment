package bowling.logic;

public class DoubleMatch extends Match
{
    private AllPlayers doublePlayers;
    private RoundRecords[][] roundRecords;

    public DoubleMatch()
    {

    }

    public DoubleMatch(AllPlayers doublePlayers, RoundRecords[][] roundRecords)
    {
        super(roundRecords, doublePlayers,"双人赛",6,10,2,60);
        this.doublePlayers = doublePlayers;
        this.roundRecords = roundRecords;
    }

    public void setPlayerRecord()
    {
        for(int i = 0;i < 60;i++)
            for(int p = 0;p < 6;p++)
                for(int q = 0;q < 10;q++)
                    doublePlayers.get(i).getDoubleRecord().add(
                            roundRecords[p][q].get(i));
    }
}
