package bowling.logic;

import java.util.Collections;
import java.util.Random;

public class Match
{
    private RoundRecords[][] roundRecords;
    private AllPlayers allPlayers;
    private String event;//记录该种比赛类型
    private int inning;//记录该比赛总局数
    private int round;//记录比赛的轮数
    private int teamMembers;//表示每一组的人数
    private int joinMembers;//表示参赛的人数
    private int existPin;//记录当前场上存在的球瓶
    private int downPin;//记录该次击倒的球数

    public Match()
    {

    }

    public Match(RoundRecords[][] roundRecords, AllPlayers allPlayers, String event, int inning, int round, int teamMembers,int joinMembers)
    {
        for(int i = 0;i < inning;i++)
            for(int j = 0;j < round;j++)
                roundRecords[i][j] = new RoundRecords();
        this.roundRecords = roundRecords;
        this.allPlayers = allPlayers;
        this.event = event;
        this.inning = inning;
        this.round = round;
        this.teamMembers = teamMembers;
        this.joinMembers = joinMembers;
    }

    public void matchBegin()
    //开始游戏
    {
        this.makeTeam();
        //先分组，并且球员已经按照组别排好了序
        for (int p = 0; p < inning; p++)
            //对每一局
        {
            for (int q = 0; q < round; q++)
                //对每一轮
            {
                for (int i = 0; i < joinMembers; i++)
                //对第p局，第q轮，第i位选手
                    play(p, q, i);
            }
            setPersonRoundRecord(p);
            setTeamRoundRecord(p);
            setPersonInningScore(p);
            setTeamInningScore(p);
        }
        setPersonMatchScore();
        setTeamMatchScore();
    }

    public void setTeamMatchScore()
    //设置小组该比赛总分
    {
        for(int p = 0;p < inning;p++)
            for(int q = 0;q < round;q++)
                for(int i = 0;i < joinMembers;i++)
                {
                    if ((i + 1) % teamMembers == 0)
                    {
                        int teamMatchScore = 0;
                        for (int j = 0; j < inning; j++)
                            teamMatchScore = teamMatchScore + roundRecords[j][0].get(i).getTeamInningScore();
                        for (int j = i; j > i - teamMembers; j--)
                            roundRecords[p][q].get(j).setTeamMatchScore(teamMatchScore);
                    }
                }
        for(int i = 0;i < joinMembers;i++)
            allPlayers.get(i).setScore(allPlayers.get(i).getScore() + roundRecords[0][0].get(i).getTeamMatchScore());
    }

    public void setPersonMatchScore()
    //设置个人该比赛总得分
    {
        for(int i  = 0;i < joinMembers;i++)
        {
            int personMatchScore = 0;
            for (int p = 0; p < inning; p++)
                    personMatchScore = personMatchScore + roundRecords[p][0].get(i).getPersonInningScore();
            for (int p = 0; p < inning; p++)
                for (int q = 0; q < round; q++)
                    roundRecords[p][q].get(i).setPersonMatchScore(personMatchScore);
        }
    }

    public void setTeamInningScore(int p)
    //设置队伍第p局总得分
    {
        for(int q = 0;q < round;q++)
            for(int i = 0;i < joinMembers;i++)
                if((i + 1) % teamMembers == 0)
                {
                    int inningScore = 0;//记录该组该局的总分
                    for(int j = i;j > i - teamMembers;j--)
                        inningScore = roundRecords[p][q].get(j).getPersonInningScore() + inningScore;
                    for(int j = i;j > i - teamMembers;j--)
                        roundRecords[p][q].get(j).setTeamInningScore(inningScore);
                }
    }

    public void setPersonInningScore(int p)
    //设置选手第p局个人总得分
    {
        for(int q = 0;q < round;q++)
            for(int i = 0;i < joinMembers;i++)
            {
                int personInningScore = 0;
                for(int j = 0;j < round;j++)
                    personInningScore = personInningScore + roundRecords[p][j].get(i).getPersonRoundScore();
                roundRecords[p][q].get(i).setPersonInningScore(personInningScore);
            }
    }

    public void setTeamRoundRecord(int p)
    //设置队伍第p局每一轮的得分
    {
        for(int q = 0;q <round;q++)
            for(int k = 0;k < joinMembers;k ++)
                if((k + 1) % teamMembers == 0)
                {
                    int roundScore = 0;//记录该组该轮的总分
                    for (int j = k; j > k - teamMembers; j--)
                        roundScore = roundRecords[p][q].get(j).getPersonRoundScore() + roundScore;
                    for (int j = k; j > k - teamMembers; j--)
                        roundRecords[p][q].get(j).setTeamRoundScore(roundScore);
                }
    }

    public void setPersonRoundRecord(int p)
    //设置选手第p局每一轮的个人得分
    {
        for(int q = 0;q < round;q++)
            for(int k = 0;k < joinMembers;k++)
                countPersonRoundScore(p, q, k);
    }

    public void countPersonRoundScore(int p,int q,int k)
    //计算选手p局q轮的个人得分
    {
        if(q < 9)
        //第十轮的得分已经设定好了
        {
            if (roundRecords[p][q].get(k).getFirstScore() == 10)
            {
                roundRecords[p][q].get(k).setScoreType("全中");
                if (q != 8 && roundRecords[p][q + 1].get(k).getFirstScore() == 10)
                    roundRecords[p][q].get(k).setPersonRoundScore
                            (
                                    roundRecords[p][q].get(k).getPersonRoundScore() +
                                            roundRecords[p][q + 1].get(k).getPersonRoundScore() +
                                            roundRecords[p][q + 2].get(k).getFirstScore()
                            );
                else
                    roundRecords[p][q].get(k).setPersonRoundScore
                            (
                                    roundRecords[p][q].get(k).getPersonRoundScore() +
                                            roundRecords[p][q + 1].get(k).getFirstScore() +
                                            roundRecords[p][q + 1].get(k).getSecondScore()
                            );
            }
            else if (roundRecords[p][q].get(k).getPersonRoundScore() == 10)
            {
                roundRecords[p][q].get(k).setScoreType("补中");
                roundRecords[p][q].get(k).setPersonRoundScore(roundRecords[p][q].get(k).getPersonRoundScore() +
                        roundRecords[p][q + 1].get(k).getFirstScore());
            }
            else
                roundRecords[p][q].get(k).setScoreType("失误");
        }
    }

    public void play(int p,int q,int i)
    //第p局,第q轮,第i位选手进行比赛
    {
        existPin = 10;
        roundRecords[p][q].add(new Record(event, allPlayers.get(i).getName(),
                allPlayers.get(i).getTeamNum(), p+1, q + 1));
        hitPins();//第一次击球
        roundRecords[p][q].get(i).setFirstScore(downPin);
        if (q != 9)
        //不是第10轮
        {
            if (existPin > 0)
            {
                hitPins();//第二次击球
                roundRecords[p][q].get(i).setSecondScore(downPin);
            }
        }
        else
        {
            if (existPin == 0)
            {
                existPin = 10;
                hitPins();
                roundRecords[p][q].get(i).setSecondScore(downPin);
                existPin = 10;
                hitPins();
                roundRecords[p][q].get(i).setThirdScore(downPin);
            }
            else
            {
                hitPins();
                roundRecords[p][q].get(i).setSecondScore(downPin);
                if (existPin == 0)
                {
                    existPin = 10;
                    hitPins();
                    roundRecords[p][q].get(i).setThirdScore(downPin);
                }
            }
        }
        roundRecords[p][q].get(i).setPersonRoundScore(
                roundRecords[p][q].get(i).getFirstScore()+
                roundRecords[p][q].get(i).getSecondScore()+
                roundRecords[p][q].get(i).getThirdScore()
        );
    }

    public void hitPins()
    {
        downPin = new Random().nextInt(existPin + 1);

        existPin = existPin - downPin;
    }

    public void makeTeam()
    //按照每一组的人数进行分组
    {
        //只需要打乱队列的排序然后再按照小组人数进行划分就行
        Collections.shuffle(allPlayers);
        for(int i = 0;i < joinMembers;i++)
            allPlayers.get(i).setTeamNum(i / teamMembers +1);
    }

    public void matchResult()
    {
        System.out.println(event + "赛果");
        for(int i = 0;i < inning;i++)
            for (int j = 0; j < round; j++)
            {
                System.out.println("第" + (i + 1) + "局"+"第" + (j + 1) + "轮");
                Collections.sort(roundRecords[i][j], (e1, e2) -> e2.getTeamRoundScore() - e1.getTeamRoundScore());
                for (int k = 0; k < joinMembers; k++)
                //每一个
                {
                    if (teamMembers != 1)
                    {
                        if (k % teamMembers == 0)
                            System.out.println("第" + roundRecords[i][j].get(k).getTeamNum() + "组，" + "总得分为：" +
                                    roundRecords[i][j].get(k).getTeamRoundScore());
                    }
                    System.out.println(roundRecords[i][j].get(k));
                }
            }
    }

    public AllPlayers checkTeamMate()
    //查看分组结果
    {
        Collections.sort(allPlayers,(e1,e2)->e1.getTeamNum() - e2.getTeamNum());
        return allPlayers;
    }
}
