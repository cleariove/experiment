package bowling.logic;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class AllPlayers extends ArrayList<Player>
{

    public AllPlayers()
    {

    }

    public void initialize() throws Exception
    //创建球员信息文件并向其中输入数据
    // 将球员信息存入列表
    {
        File file = new File("player.txt");
        try(PrintWriter printWriter = new PrintWriter(file))
        {
            printWriter.print("zhangsan m\n" +
                    "lisi f\n" +
                    "wangwu m\n" +
                    "zhaoliu f\n" +
                    "qianqi m\n" +
                    "sunba f\n" +
                    "yangjiu m\n" +
                    "wushi f\n" +
                    "xiaoming m\n" +
                    "xiaohong f\n" +
                    "xiaohei m\n" +
                    "xiaobai f\n" +
                    "dahuang m\n" +
                    "erha f\n" +
                    "lihua m \n" +
                    "xiaofang f\n" +
                    "xiaoqiang m\n" +
                    "apple f\n" +
                    "banana m\n" +
                    "watermelon f\n" +
                    "peach m\n" +
                    "lemon f\n" +
                    "pear m\n" +
                    "grape f\n" +
                    "tomato m \n" +
                    "strawberry f\n" +
                    "orange m\n" +
                    "cherry f\n" +
                    "blueberry m\n" +
                    "peanut f\n" +
                    "pomelo m\n" +
                    "mango f\n" +
                    "blue m\n" +
                    "red f\n" +
                    "black m\n" +
                    "white f\n" +
                    "brown m\n" +
                    "yellow f\n" +
                    "pink m\n" +
                    "green f\n" +
                    "gray m\n" +
                    "gold f\n" +
                    "purple m\n" +
                    "lion f\n" +
                    "tiger m\n" +
                    "pig f\n" +
                    "cow m\n" +
                    "wolf f\n" +
                    "cat m \n" +
                    "rabbit f\n" +
                    "dog m\n" +
                    "monkey f\n" +
                    "fish m\n" +
                    "duck f\n" +
                    "horse m\n" +
                    "bird f\n" +
                    "mouse m\n" +
                    "sheep f\n" +
                    "deer m\n" +
                    "panda f");
        }
        try(Scanner sc  = new Scanner(file))
        {
            Integer i = 1;
            while(sc.hasNext())
            {
                this.add(new Player(sc.next(), sc.next(), String.valueOf(i)));
                i++;
            }
        }
    }

    public void sortPlayerByScore()
    //按照当前总分分数高低（相同时按每种比赛的个人得分）排序
    {
        Collections.sort(this,(e1, e2)->
        {
            if(e2.getScore() != e1 .getScore())
                return e2.getScore() - e1.getScore();
            else  if(e2.getSingleRecord().get(0).getPersonMatchScore() !=
                    e1.getSingleRecord().get(0).getPersonMatchScore())
                return e2.getSingleRecord().get(0).getPersonMatchScore()
                        - e1.getSingleRecord().get(0).getPersonMatchScore();
            else if(e2.getDoubleRecord().get(0).getPersonMatchScore() !=
                    e1.getDoubleRecord().get(0).getPersonMatchScore())
                return e2.getDoubleRecord().get(0).getPersonMatchScore() -
                        e1.getDoubleRecord().get(0).getPersonMatchScore();
            else if(e2.getTripleRecord().get(0).getPersonMatchScore() !=
                    e1.getTripleRecord().get(0).getPersonMatchScore())
                return e2.getTripleRecord().get(0).getPersonMatchScore() -
                        e1.getTripleRecord().get(0).getPersonMatchScore();
            else if(e2.getPentaRecord().get(0).getPersonMatchScore() !=
                    e1.getPentaRecord().get(0).getPersonMatchScore())
                return e2.getPentaRecord().get(0).getPersonMatchScore() -
                        e1.getPentaRecord().get(0).getPersonMatchScore();
            else return e2.getId().compareTo(e1.getId());
        });
    }

    public void sortPlayerBySingleScore()
    //按照选手单人赛总成绩（相同则以最后一轮的总分）排序
    {
        Collections.sort(this,(e1,e2)->
        {
            if(e2.getSingleRecord().get(0).getPersonMatchScore() !=
                    e1.getSingleRecord().get(0).getPersonMatchScore())
                return e2.getSingleRecord().get(0).getPersonMatchScore() -
                    e1.getSingleRecord().get(0).getPersonMatchScore();
            else for(int i = 59;i > 0;i--)
            {
                if(e2.getSingleRecord().get(i).getPersonRoundScore() !=
                        e1.getSingleRecord().get(i).getPersonRoundScore())
                    return e2.getSingleRecord().get(i).getPersonRoundScore() -
                            e1.getSingleRecord().get(i).getPersonRoundScore();
            }
            return e2.getId().compareTo(e1.getId());
        });
    }

    public void sortPlayerByDoubleRecord()
    {
        Collections.sort(this,(e1,e2)->
        {
            if(e2.getDoubleRecord().get(0).getTeamMatchScore() !=
                e1.getDoubleRecord().get(0).getTeamMatchScore())
                return e2.getDoubleRecord().get(0).getTeamMatchScore() -
                        e1.getDoubleRecord().get(0).getTeamMatchScore();
            else return e1.getDoubleRecord().get(0).getTeamNum() -
                    e2.getDoubleRecord().get(0).getTeamNum();
        });
    }

    public void sortPlayerByTripleRecord()
    {
        Collections.sort(this,(e1,e2)->
        {
            if(e2.getTripleRecord().get(0).getTeamMatchScore() !=
                    e1.getTripleRecord().get(0).getTeamMatchScore())
                return e2.getTripleRecord().get(0).getTeamMatchScore() -
                        e1.getTripleRecord().get(0).getTeamMatchScore();
            else return e1.getTripleRecord().get(0).getTeamNum() -
                    e2.getTripleRecord().get(0).getTeamNum();
        });
    }

    public void sortPlayerByPentaRecord()
    {
        Collections.sort(this,(e1,e2)->
        {
            if(e2.getPentaRecord().get(0).getTeamMatchScore() !=
                    e1.getPentaRecord().get(0).getTeamMatchScore())
                return e2.getPentaRecord().get(0).getTeamMatchScore() -
                        e1.getPentaRecord().get(0).getTeamMatchScore();
            else return e1.getPentaRecord().get(0).getTeamNum() -
                    e2.getPentaRecord().get(0).getTeamNum();
        });
    }

    public void sortPlayerByClassicRecord(AllPlayers classicPlayers)
    {
        Collections.sort(classicPlayers,(e1,e2)->
        {
            if(e2.getClassicRecord().get(0).getPersonMatchScore() !=
                    e1.getClassicRecord().get(0).getPersonMatchScore())
                return e2.getClassicRecord().get(0).getPersonMatchScore() -
                        e1.getClassicRecord().get(0).getPersonMatchScore();
            else for(int i = 15;i > 0;i--)
            {
                if(e2.getClassicRecord().get(i).getPersonRoundScore() !=
                        e1.getClassicRecord().get(i).getPersonRoundScore())
                    return e2.getClassicRecord().get(i).getPersonRoundScore() -
                            e1.getClassicRecord().get(i).getPersonRoundScore();
            }
            return e2.getId().compareTo(e1.getId());
        });
    }
}
