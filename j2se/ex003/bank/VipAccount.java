package ex003.bank;

public class VipAccount extends Account
{
    private double limit;

    public VipAccount()
    {
        super();
        this.setLimit(-10000);
    }

    public VipAccount(String name, String id, double money)
    {
        super(name, id, money);
        this.setLimit(-10000);
    }

    public double getLimit()
    {
        return limit;
    }

    public void setLimit(double limit)
    {
        this.limit = limit;
    }
}
