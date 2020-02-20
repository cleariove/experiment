package ex003.bank;

import java.util.ArrayList;

public class Account
{
    private String name;

    private String id;

    private double money;

    private ArrayList<String> transactionRecord = new ArrayList<>();


    public Account()
    {
    }

    public Account(String name, String id, double money)
    {
        this.name = name;
        this.id = id;
        this.money = money;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getId()
    {
        return id;
    }

    public void setId(String id)
    {
        this.id = id;
    }

    public double getMoney()
    {
        return money;
    }

    public void setMoney(double money)
    {
        this.money = money;
    }

    public ArrayList<String> getTransactionRecord()
    {
        return transactionRecord;
    }

    public boolean isVipAccount()
    {
        return this.getId().toLowerCase().matches("(vip).*");
    }

    public boolean isBussinessAccount()
    {
        return this.getId().toLowerCase().matches("(bussiness).*");
    }
}
