package ex002.checksecret;

public class Check extends Secret
{
   public Check()
   {

   }
   public Check(String secret)
   {
       super(secret);
   }

   public String CheckLength()
   {
       return super.Length()<8? "请输入8位以上的密码":"Valid Password";
   }
   public String CheckChar()
   {
       if(super.getSecret().matches("[0-9a-zA-Z]*"))
           return "Valid Password";
       else
           return "密码只能包括数字和大小写字母";
   }
   public String CheckNum()
   {
       if(super.getSecret().matches("[a-zA-Z]*[0-9][a-zA-Z]*[0-9][a-zA-Z]*[0-9][a-zA-Z0-9]*"))
           return "Valid Password";
       else
           return "密码请包含至少三个数字";
   }

    @Override
    public void setSecret(String secret)
    {
        super.setSecret(secret);
    }
}
