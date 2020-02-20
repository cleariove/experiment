package bowling.logic;

public class Record
{
    private String event;//比赛类型
    private String name;//选手姓名
    private int teamNum;//选手所在队伍编号
    private int inning;//局数
    private int round;//轮数
    private int firstScore;//第一次扔球得分
    private int secondScore;//第二次扔球得分
    private int thirdScore;//第三次扔球得分
    private String scoreType;//得分类型是全中,补中还是失误
    private int personRoundScore;//选手该轮总得分，
    private int personInningScore;//选手该局总分
    private int teamRoundScore;//该轮队伍总得分，
    private int teamInningScore;//该局队伍总分
    private int personMatchScore;//该比赛选手个人得分
    private int teamMatchScore;//该比赛队伍总得分

    public Record()
    {

    }

    public Record(String event, String name, int teamNum, int inning, int round)
    {
        this.event = event;
        this.name = name;
        this.teamNum = teamNum;
        this.inning = inning;
        this.round = round;
    }

    public int getTeamNum()
    {
        return teamNum;
    }

    public void setTeamNum(int teamNum)
    {
        this.teamNum = teamNum;
    }

    public int getInning()
    {
        return inning;
    }

    public void setInning(int inning)
    {
        this.inning = inning;
    }

    public int getRound()
    {
        return round;
    }

    public void setRound(int round)
    {
        this.round = round;
    }

    public int getFirstScore()
    {
        return firstScore;
    }

    public void setFirstScore(int firstScore)
    {
        this.firstScore = firstScore;
    }

    public int getSecondScore()
    {
        return secondScore;
    }

    public void setSecondScore(int secondScore)
    {
        this.secondScore = secondScore;
    }

    public int getPersonRoundScore()
    {
        return personRoundScore;
    }

    public void setPersonRoundScore(int personRoundScore)
    {
        this.personRoundScore = personRoundScore;
    }

    public int getPersonInningScore()
    {
        return personInningScore;
    }

    public void setPersonInningScore(int personInningScore)
    {
        this.personInningScore = personInningScore;
    }

    public int getTeamRoundScore()
    {
        return teamRoundScore;
    }

    public void setTeamRoundScore(int teamRoundScore)
    {
        this.teamRoundScore = teamRoundScore;
    }

    public int getTeamInningScore()
    {
        return teamInningScore;
    }

    public void setTeamInningScore(int teamInningScore)
    {
        this.teamInningScore = teamInningScore;
    }

    public int getThirdScore()
    {
        return thirdScore;
    }

    public void setThirdScore(int thirdScore)
    {
        this.thirdScore = thirdScore;
    }

    @Override
    public String toString()
    {
        return "Record{" +
                "event='" + event + '\'' +
                ", name='" + name + '\'' +
                ", teamNum=" + teamNum +
                ", inning=" + inning +
                ", round=" + round +
                ", firstScore=" + firstScore +
                ", secondScore=" + secondScore +
                ", thirdScore=" + thirdScore +
                ", personRoundScore=" + personRoundScore +
                ", personInningScore=" + personInningScore +
                ", teamRoundScore=" + teamRoundScore +
                ", teamInningScore=" + teamInningScore +
                ", personMatchScore=" + personMatchScore +
                ", teamMatchScore=" + teamMatchScore +
                '}';
    }

    public int getPersonMatchScore()
    {
        return personMatchScore;
    }

    public void setPersonMatchScore(int personMatchScore)
    {
        this.personMatchScore = personMatchScore;
    }

    public int getTeamMatchScore()
    {
        return teamMatchScore;
    }

    public void setTeamMatchScore(int teamMatchScore)
    {
        this.teamMatchScore = teamMatchScore;
    }

    public String getScoreType()
    {
        return scoreType;
    }

    public void setScoreType(String scoreType)
    {
        this.scoreType = scoreType;
    }
}
