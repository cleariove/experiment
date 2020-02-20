package ex001.calculate;

public class SplitString
{
    private String s = new String();
    private String[] s1;
    private char operator;
    private double num1;
    private double num2;

    public SplitString()
    {

    }

    public void split()
    {
        s1 = s.split("[+*/-]");
        operator = s.charAt(s1[0].length());
        num1 = Double.valueOf(s1[0]);
        num2 = Double.valueOf(s1[1]);
    }

    public String[] getS1()
    {
        return s1;
    }

    public void setS1(String[] s1)
    {
        this.s1 = s1;
    }

    public String getS()
    {
        return s;
    }

    public void setS(String s)
    {
        this.s = s;
    }


    public char getOperator()
    {
        return operator;
    }

    public void setOperator(char operator)
    {
        this.operator = operator;
    }

    public double getNum1()
    {
        return num1;
    }

    public void setNum1(double num1)
    {
        this.num1 = num1;
    }

    public double getNum2()
    {
        return num2;
    }

    public void setNum2(double num2)
    {
        this.num2 = num2;
    }
}
