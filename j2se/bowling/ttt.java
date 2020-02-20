package bowling;

import bowling.logic.AllPlayers;
import bowling.logic.RoundRecords;
import bowling.logic.SingleMatch;
import java.sql.*;

public class ttt
{
    public static void main(String[] args)
    {
        AllPlayers allPlayers = new bowling.logic.AllPlayers();
        Connection conn;
        Statement stmt;
        try
        {
            allPlayers.initialize();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        RoundRecords[][] singleRecords = new RoundRecords[6][10];
        SingleMatch singleMatch = new SingleMatch(allPlayers,singleRecords);
        singleMatch.matchBegin();
        singleMatch.setPlayerRecord();
        allPlayers.sortPlayerBySingleScore();
        try{

            //2.加载驱动程序

            Class.forName("com.mysql.cj.jdbc.Driver");

            //3.创建连接

            conn= DriverManager.getConnection(

                    "jdbc:mysql://localhost:3306/lxk",

                    "root","123456");
            if (!conn.isClosed()) {
                System.out.println("数据库连接成功");
            }
//
//            4.创建执行语句
//            String sql = "select * from words";
//            PreparedStatement pstmt = conn.prepareStatement(sql);
            stmt = conn.createStatement();

            for(int i = 0;i < 6;i++)
                for(int j = 0;j < 10;j++)
                    for(int k = 0;k < 60;k++)
                    {
                        stmt.executeUpdate("insert into record values(singleRecords[i][j].get(k).getEvent()," +
                                "singleRecords[i][j].get(k).getName(),singleRecords[i][j].get(k).getTeamNum()," +
                                "singleRecords[i][j].get(k).getInning(),singleRecords[i][j].get(k).getRound," +
                                "singleRecords[i][j].get(k).getFirstScore(),singleRecords[i][j].get(k).getSecondScore()," +
                                "singleRecords[i][j].get(k).getThirdScore,singleRecords[i][j].get(k).getScoreType()," +
                                "singleRecords[i][j].get(k).getPersonRoundScore()," +
                                "singleRecords[i][j].get(k).getPersonInningScore()," +
                                "singleRecords[i][j].get(k).getTeamRoundScore()," +
                                "singleRecords[i][j].get(k).getTeamInningScore()," +
                                "singleRecords[i][j].get(k).getPersonMatchScore()," +
                                "singleRecords[i][j].get(k).getTeamMatchScore())");
                    }



            //5执行SQL操作

//            ResultSet rs= stmt.executeQuery(sql);

            //6.处理结果集

//            while(rs.next()){
//
//                System.out.printf("%d,%s,%s",rs.getInt("id"),
//
//                        rs.getString("name"),
//
//                        rs.getString("explanation"));
//
//                System.out.println();
//
//            }

            //7.关闭

//            rs.close();

//            pstmt.close();

            conn.close();

        }catch (ClassNotFoundException e)
        {
            System.out.println("数据库驱动没有安装");
        }
        catch (SQLException e)
        {
            System.out.println("数据库连接失败");
        }


    }
}
