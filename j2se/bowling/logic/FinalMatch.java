package bowling.logic;

public class FinalMatch extends Match
{
    private AllPlayers players;
    private RoundRecords[][] finalRecords;

    public FinalMatch()
    {

    }

    public FinalMatch(AllPlayers players, RoundRecords[][] finalRecords,String event)
    {
        super(finalRecords,players,event,2,10,1,2);
        this.players = players;
        this.finalRecords = finalRecords;
    }

    public void setPlayerRecords(int k)
    {
        for(int i = 0;i < 2;i++)
            for(int p = 0;p < 2;p++)
                for(int q = 0;q < 10;q++)
                    players.get(i).getFinalRecord()[k].add(
                            finalRecords[p][q].get(i));
    }
}
