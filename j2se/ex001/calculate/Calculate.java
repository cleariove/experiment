package ex001.calculate;

public class Calculate
{
    private double num1,num2;
    private char operator;
    public Calculate()
    {

    }

    public double getNum1()
    {
        return num1;
    }

    public double getNum2()
    {
        return num2;
    }

    public double getResult(double num1,double num2,char operator)
    {
        double result = 1;
        switch (operator)
        {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '/':
                if(num2 == 0)
                    result = 0;
                else
                    result = num1 / num2;
                break;
            case '*':
                result = num1 * num2;
                break;
        }
        return result;
    }

    public void setNum1(double num1)
    {
        this.num1 = num1;
    }

    public void setNum2(double num2)
    {
        this.num2 = num2;
    }

    public char getOperator()
    {
        return operator;
    }

    public void setOperator(char operator)
    {
        this.operator = operator;
    }
}
