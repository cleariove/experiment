package bowling.logic;

public class SingleMatch extends Match
{
    private AllPlayers singlePlayers;
    private RoundRecords[][] roundRecords;

    public SingleMatch()
    {

    }

    public SingleMatch(AllPlayers singlePlayers, RoundRecords[][] roundRecords)
    {
        super(roundRecords, singlePlayers,"单人赛",6,10,1,60);
        this.singlePlayers = singlePlayers;
        this.roundRecords = roundRecords;
    }

    public void setPlayerRecord()
    {
        for(int i = 0;i < 60;i++)
            for(int p = 0;p < 6;p++)
                for(int q = 0;q < 10;q++)
                    singlePlayers.get(i).getSingleRecord().add(
                            roundRecords[p][q].get(i));
    }

    public void getPlayerBySingleScore(int rank)
    {
        singlePlayers.sortPlayerBySingleScore();
        System.out.println(singlePlayers.get(rank - 1));
    }
}
