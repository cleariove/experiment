package ex003.bank;

public class BussinessAccount extends Account
{
    private double interest;


    public BussinessAccount()
    {
    }

    public BussinessAccount(String name, String id, double money)
    {
        super(name, id, money);
    }


    public double getInterest()
    {
        return interest;
    }

    public void setInterest(double interest)
    {
        this.interest = interest;
    }

}
