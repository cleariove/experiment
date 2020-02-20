package ex003.bank;

import java.util.ArrayList;
import java.util.Scanner;


public class Atm
{
    private ArrayList<Account> accounts = new ArrayList<>();
    Scanner input = new Scanner(System.in);
    private Transaction transaction = new Transaction();

    public Atm()
    {

    }


    public void display()
    {
        while (true)
        {
            this.menu1();
            System.out.println("请输入你的选择:");
            switch (input.nextInt())
            {
                case 1:
                    this.openAccout();
                    break;
                case 2:
                    System.out.println("请输入账号id:");
                    this.logIn(input.next());
                    break;
                case 3:
                    return;
                default:
                    System.out.println("输入有误！");
                    break;
            }
        }
    }

    public void menu2()
    {
        System.out.println("------请选择要进行的操作-------");
        System.out.println("1.存钱");
        System.out.println("2.取钱");
        System.out.println("3.转账");
        System.out.println("4.交易记录");
        System.out.println("5.查询余额");
        System.out.println("6.贷款");
        System.out.println("7.放贷");
        System.out.println("8.登出");
        System.out.println("-------------------------------");
    }

    public void menu1()
    {
        System.out.println("-------欢迎来到银行系统-------");
        System.out.println("1.开户(vip账户请以vip开头,bussiness账户请以bussiness开头)");
        System.out.println("2.登陆");
        System.out.println("3.退出");
        System.out.println("------------------------------");
    }

    public int getIndex(String id)
            //得到id对应的用户在列表中的位置
    {
        int i = 0;
        for(;i < accounts.size();i++)
        {
            if((accounts.get(i).getId()).equals(id))
                break;
        }
        if(i != accounts.size())
            return i;
        return -1;
    }

    public void logIn(String id)
    {
        int index = this.getIndex(id);
        while(index < 0)
        {
            System.out.println("账户不存在!重新输入?[Y/N]:");
            if(input.next().matches("[nN]"))
            {
                return ;
            }
            System.out.println("请输入账户id:");
            id = input.next();
            index = this.getIndex(id);
        }
        while(true)
        {
            this.menu2();
            System.out.println("请输入你的选择:");
            switch (input.nextInt())
            {
                case 1:
                    System.out.println("请输入金额:");
                    transaction.depose(accounts.get(index),input.nextDouble());
                    accounts.get(index).getTransactionRecord().add(transaction.getDescription());
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
                case 2:
                    System.out.println("请输入金额:");
                    double amount1 = input.nextDouble();
                    double limit = 0;
                    if(accounts.get(index) instanceof VipAccount)
                    {
                        limit = ((VipAccount)accounts.get(index)).getLimit();
                    }

                    if(accounts.get(index).getMoney() - amount1 < limit)
                        System.out.println("余额不足,交易失败！");
                    else
                    {
                        transaction.withdraw(accounts.get(index), amount1);
                        accounts.get(index).getTransactionRecord().add(transaction.getDescription());
                    }
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
                case 3:
                    System.out.println("请输入金额:");
                    double amount2 = input.nextDouble();
                    if((!accounts.get(index).isVipAccount()) && accounts.get(index).getMoney() - amount2 < 0)
                        System.out.println("余额不足,交易失败！");
                    else if(accounts.get(index).getMoney() - amount2 < ((VipAccount)accounts.get(index)).getLimit())
                        System.out.println("余额不足,交易失败！");
                    else
                    {
                        System.out.println("请输入对方账户id:");
                        int index2 = this.getIndex(input.next());
                        if(index2 < 0)
                        {
                            System.out.println("对方账户不存在");
                        }
                        else
                        {
                            transaction.transfer(accounts.get(index),accounts.get(index2),amount2);
                            accounts.get(index).getTransactionRecord().add(transaction.getDescription());
                        }
                    }
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
                case 4:
                    for(String e:accounts.get(index).getTransactionRecord())
                        System.out.println(e);
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
                case 5:
                    if(accounts.get(index).isVipAccount())
                    {
                        System.out.println("余额为:" + accounts.get(index).getMoney()+",总额度为:" +
                                Math.abs(((VipAccount)accounts.get(index)).getLimit()) + "，可用总资金为:" +
                                (accounts.get(index).getMoney() + Math.abs(((VipAccount)accounts.get(index)).getLimit())));
                    }
                    else
                        System.out.println("余额为:" + accounts.get(index).getMoney());
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
                case 6:
                        System.out.println("请输入贷款金额");
                        transaction.loan(accounts.get(index),input.nextDouble());
                        accounts.get(index).getTransactionRecord().add(transaction.getDescription());
                        System.out.println("操作成功！是否继续[Y/N]?");
                        if(input.next().matches("[nN]"))
                        {
                            return ;
                        }
                        break;
                case 7:
                        System.out.println("请输入对方的账户id:");
                        int index3 = this.getIndex(input.next());
                        System.out.println("请输入放贷金额:");
                        double amount3 = input.nextDouble();
                        if(amount3 > accounts.get(index).getMoney())
                            System.out.println("余额不足");
                        else
                        {
                            System.out.println("请输入利息:");
                            double interest = input.nextDouble();
                            transaction.lend(accounts.get(index), accounts.get(index3), amount3, interest);
                            accounts.get(index).getTransactionRecord().add(transaction.getDescription());
                        }
                        System.out.println("是否继续[Y/N]?");
                        if(input.next().matches("[nN]"))
                        {
                            return ;
                        }
                        break;
                case 8:
                    return;
                default:
                    System.out.println("输入有误！");
                    System.out.println("操作成功！是否继续[Y/N]?");
                    if(input.next().matches("[nN]"))
                    {
                        return ;
                    }
                    break;
            }
        }
    }

    public void openAccout()
            //新建一个用户
    {
        Account account = new Account();
        System.out.println("请输入开户人姓名:");
        account.setName(input.next());
        System.out.println("请输入编号:");
        account.setId(input.next());
        System.out.println("请输入存款:");
        account.setMoney(input.nextDouble());
        if(account.getId().toLowerCase().matches("(vip).*"))
        {
            System.out.println("vip账户创建完成");
            account = new VipAccount(account.getName(),account.getId(),account.getMoney());
        }
        if(account.getId().matches("(bussiness).*"))
        {
            System.out.println("business账户创建完成");
            account = new BussinessAccount(account.getName(),account.getId(),account.getMoney());
        }
        accounts.add(account);
    }
}
