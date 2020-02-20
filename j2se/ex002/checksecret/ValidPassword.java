package ex002.checksecret;

public class ValidPassword
{
    private Check check = new Check();
    public ValidPassword()
    {

    }
    public ValidPassword(String string)
    {
        check.setSecret(string);
    }
    public void isValidPassword()
    {
        if(check.CheckLength()=="Valid Password")
        {
            if(check.CheckChar()=="Valid Password")
            {
                if(check.CheckNum()=="Valid Password")
                    System.out.println("Valid Password");
                else
                    System.out.println(check.CheckNum());
            }
            else
                System.out.println(check.CheckChar());
        }
        else
            System.out.println(check.CheckLength());
    }
}
