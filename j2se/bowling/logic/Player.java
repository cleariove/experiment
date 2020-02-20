package bowling.logic;

public class Player
{
    private String name;
    private String sex;
    private String id;
    private int score;//当前总分
    private int teamNum;//选手某一场比赛当前的组别号
    private RoundRecords singleRecord;
    private RoundRecords doubleRecord;
    private RoundRecords tripleRecord;
    private RoundRecords pentaRecord;
    private RoundRecords classicRecord = new RoundRecords();
    private RoundRecords[] finalRecord = new RoundRecords[3];

    public Player()
    {

    }

    public Player(String name, String sex, String id)
    {
        this.name = name;
        this.sex = sex;
        this.id = id;
        this.score = 0;
        this.singleRecord = new RoundRecords();
        this.doubleRecord = new RoundRecords();
        this.tripleRecord = new RoundRecords();
        this.pentaRecord = new RoundRecords();
    }

    @Override
    public String toString()
    {
        return "Player{" +
                "name='" + name + '\'' +
                ", sex='" + sex + '\'' +
                ", id='" + id + '\'' +
                ", score=" + score +
                '}';
    }

    public void setScore(int score)
    {
        this.score = score;
    }

    public String getName()
    {
        return name;
    }

    public String getSex()
    {
        return sex;
    }

    public String getId()
    {
        return id;
    }

    public int getScore()
    {
        return score;
    }

    public int getTeamNum()
    {
        return teamNum;
    }

    public void setTeamNum(int teamNum)
    {
        this.teamNum = teamNum;
    }

    public void setSingleRecord(RoundRecords singleRecord)
    {
        this.singleRecord = singleRecord;
    }

    public void setDoubleRecord(RoundRecords doubleRecord)
    {
        this.doubleRecord = doubleRecord;
    }

    public void setTripleRecord(RoundRecords tripleRecord)
    {
        this.tripleRecord = tripleRecord;
    }

    public void setPentaRecord(RoundRecords pentaRecord)
    {
        this.pentaRecord = pentaRecord;
    }

    public void setClassicRecord(RoundRecords classicRecord)
    {
        this.classicRecord = classicRecord;
    }

    public RoundRecords getSingleRecord()
    {
        return singleRecord;
    }

    public RoundRecords getDoubleRecord()
    {
        return doubleRecord;
    }

    public RoundRecords getTripleRecord()
    {
        return tripleRecord;
    }

    public RoundRecords getPentaRecord()
    {
        return pentaRecord;
    }

    public RoundRecords getClassicRecord()
    {
        return  classicRecord;
    }

    public RoundRecords[] getFinalRecord()
    {
        return finalRecord;
    }

    public void setFinalRecord(RoundRecords[] finalRecord)
    {
        this.finalRecord = finalRecord;
    }
}
