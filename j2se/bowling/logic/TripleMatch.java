package bowling.logic;

public class TripleMatch extends Match
{
    private AllPlayers triplePlayers;
    private RoundRecords[][] roundRecords;

    public TripleMatch()
    {
    }

    public TripleMatch(AllPlayers triplePlayers, RoundRecords[][] roundRecords)
    {
        super(roundRecords, triplePlayers,"三人赛",6,10,3,60);
        this.triplePlayers = triplePlayers;
        this.roundRecords = roundRecords;
    }

    public void setPlayerRecord()
    {
        for(int i = 0;i < 60;i++)
            for(int p = 0;p < 6;p++)
                for(int q = 0;q < 10;q++)
                    triplePlayers.get(i).getTripleRecord().add(
                            roundRecords[p][q].get(i));
    }

}