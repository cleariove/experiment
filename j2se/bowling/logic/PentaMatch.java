package bowling.logic;


public class PentaMatch extends Match
{
    private AllPlayers pentaPlayers;
    private RoundRecords[][] roundRecords;

    public PentaMatch()
    {

    }

    public PentaMatch(AllPlayers pentaPlayers, RoundRecords[][] roundRecords)
    {
        super(roundRecords, pentaPlayers,"五人赛",6,10,5,60);
        this.pentaPlayers = pentaPlayers;
        this.roundRecords = roundRecords;
    }

    public void setPlayerRecord()
    {
        for(int i = 0;i < 60;i++)
            for(int p = 0;p < 6;p++)
                for(int q = 0;q < 10;q++)
                    pentaPlayers.get(i).getPentaRecord().add(
                            roundRecords[p][q].get(i));
    }
}
