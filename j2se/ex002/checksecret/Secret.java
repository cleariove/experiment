package ex002.checksecret;

public class Secret
{
    private String secret;

    public Secret()
    {

    }

    public Secret(String secret)
    {
        this.secret = secret;
    }

    public int Length()
    {
        return secret.length();
    }

    public String getSecret()
    {
        return secret;
    }

    public void setSecret(String secret)
    {
        this.secret = secret;
    }
}
