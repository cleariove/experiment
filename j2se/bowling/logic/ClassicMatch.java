package bowling.logic;

public class ClassicMatch extends Match
{
    private AllPlayers classicPlayers;
    private RoundRecords[][] roundRecords;

    public ClassicMatch()
    {

    }

    public ClassicMatch(AllPlayers classicPlayers, RoundRecords[][] roundRecords)
    {
        super(roundRecords, classicPlayers,"精英赛",15,10,1,16);
        this.classicPlayers = classicPlayers;
        this.roundRecords = roundRecords;
    }

    public void setPlayerRecord()
    {
        for(int i = 0;i < 16;i++)
            for(int p = 0;p < 15;p++)
                for(int q = 0;q < 10;q++)
                    classicPlayers.get(i).getClassicRecord().add(
                            roundRecords[p][q].get(i));
    }

}
