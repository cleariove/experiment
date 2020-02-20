package ex003.bank;

import java.util.Date;
import java.util.Random;

public class Transaction
{
    private String date;

    private Type type;

    private Double amount;

    private Double balance;

    private String description;

    public Transaction()
    {
    }

    public void depose(Account a1,double amount)
    {
        a1.setMoney(a1.getMoney() + amount);
        this.setBalance(a1.getMoney());
        this.setDate();
        this.setAmount(amount);
        this.setType(Type.D);
        this.setDescription(this.getType().getOperate() + " " +
                this.getAmount() + " at " +
                this.getDate() + " Remaining:" +
                this.getBalance());
    }

    public void withdraw(Account a1,double amount)
    {
        a1.setMoney(a1.getMoney() - amount);
        this.setBalance(a1.getMoney());
        this.setDate();
        this.setAmount(amount);
        this.setType(Type.W);
        this.setDescription(this.getType().getOperate() +
                " " + this.getAmount() + " at " +
                this.getDate() + " Remaining:" +
                this.getBalance());
    }

    public void transfer(Account a1,Account a2,double amount)
    {
        a1.setMoney(a1.getMoney() - amount);
        a2.setMoney(a2.getMoney() + amount);
        this.setBalance(a1.getMoney());
        this.setDate();
        this.setAmount(amount);
        this.setType(Type.T);
        this.setDescription(this.getType().getOperate() + " " +
                this.getAmount() + " to " +
                a2.getName() +
                " at " +
                this.getDate() + " remaining:" +
                this.getBalance());
        a2.getTransactionRecord().add(this.getType().getOperate() + " " +
                this.getAmount() + " from " +
                a1.getName() +
                " at " +
                this.getDate() + " remaining:" +
                a2.getMoney());
    }

    public void loan(Account a1,double amount)
    {
        if(a1.isBussinessAccount())
        {
            ((BussinessAccount)a1).setInterest((new Random().nextInt(11) + 40.0) / 100);
            System.out.println("当前利率为" + ((BussinessAccount)a1).getInterest());
            a1.setMoney(a1.getMoney() + amount);
            this.setBalance(a1.getMoney());
            this.setDate();
            this.setAmount(amount);
            this.setType(null);
            this.setDescription( "贷款" +
                    this.getAmount() + "，利息为"+
                    ((BussinessAccount)a1).getInterest() +
                    " at " +
                    this.getDate() + " remaining:" +
                    this.getBalance());
        }
        else
            System.out.println("账户权限无法贷款");
    }

    public void lend(Account a1,Account a2,double amount,double interest)
    {
        if(a1.isBussinessAccount() && a2.isBussinessAccount())
        {
            ((BussinessAccount)a1).setInterest(interest);
            a1.setMoney(a1.getMoney() - amount);
            this.setBalance(a1.getMoney());
            this.setDate();
            this.setAmount(amount);
            this.setType(null);
            this.setDescription("放贷 " +
                    + this.getAmount() + " to " +
                    a2.getName() +
                    " at " +
                    this.getDate() + " Remaining:" +
                    this.getBalance());
            a2.setMoney(a2.getMoney() + amount);
            a2.getTransactionRecord().add("贷款" +
                    this.getAmount() +
                    " from " + a1.getName() + " at " +
                    this.getDate() + " Remaining:" +
                    a2.getMoney());
        }
        else
            System.out.println("双方账户之一权限不够");
    }

    public String getDate()
    {
        return date;
    }

    public void setDate()
    {
        this.date = new Date().toString();
    }

    public Type getType()
    {
        return type;
    }

    public void setType(Type type)
    {
        this.type = type;
    }

    public Double getAmount()
    {
        return amount;
    }

    public void setAmount(Double amount)
    {
        this.amount = amount;
    }

    public Double getBalance()
    {
        return balance;
    }

    public void setBalance(Double balance)
    {
        this.balance = balance;
    }

    public String getDescription()
    {
        return description;
    }

    public void setDescription(String description)
    {
        this.description = description;
    }

    @Override
    public String toString()
    {
        return "Transaction{" +
                "date='" + date + '\'' +
                ", type=" + type +
                ", amount=" + amount +
                ", balance=" + balance +
                ", description='" + description + '\'' +
                '}';
    }
}
