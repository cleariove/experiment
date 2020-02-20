package ex003.bank;

public enum Type
{
    W("Withdraw"), D("Depose"), T("Transfer");

    private String operate;

    private Type(String operate)
    {
        this.operate = operate;
    }

    public String getOperate()
    {
        return operate;
    }
}
