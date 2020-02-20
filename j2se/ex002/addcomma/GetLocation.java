package ex002.addcomma;

public class GetLocation
{
    private StringBuffer string;

    public GetLocation()
    {

    }
    public GetLocation(StringBuffer string)
    {
        this.string = string;
    }

    public int getCommaLocation(int index)
    //找到逗号的位置
    {
        return string.indexOf(",",index);
    }


    public String getPreviousWord(int index)
    //找到逗号前的单词的起始位置,index代表逗号的位置
    {
        //可以避免因别的符号而导致未切割的情况
        String string1 = new String(string);
        string1 = string1.replaceAll("\\p{P}"," ");
        int a = string1.lastIndexOf(" ",index - 1);
        return string1.substring(a + 1,index);
    }

    public String getLaterWord(int index)
    //找到逗号后的单词的结束位置
    {
        //可以避免因别的符号而导致未切割的情况
        String string1 = new String(string);
        string1 = string1.replaceAll("\\p{P}"," ");
        int a = string1.indexOf(" ",index + 1);
        if(a <= -1)
            a = string1.length();
        return string1.substring(index + 1,a);
    }

    public int laterLocation(String string,int index)
    //合法的可在单词后面加逗号的位置
    {
        int a = this.string.indexOf(string,index);
        int location = a + string.length();
        while(a != -1 && location < this.string.length() && this.string.charAt(location) != ' ')
        //防止该位置已经有别的标点符号
        {
            a = this.string.indexOf(string,location + 1);
            location = a + string.length();
        }
        if(a == -1 || location >= this.string.length())
            return -1;
        else
            return location;
    }

    public int previousLocation(String string,int index)
    //合法的可在单词前面加逗号的位置
    {
        int a = this.string.indexOf(string,index);
        if(a == 0)
            a = this.string.indexOf(string,a + 1);
        while(this.string.charAt(a - 1 < 0 ? 0 : a - 1) != ' ' && a <= this.string.length() && a != -1)
        //防止该位置有别的标点符号
            a = this.string.indexOf(string, a + 2);
        return a;
    }

    public StringBuffer getString()
    {
        return string;
    }

    public void setString(StringBuffer string)
    {
        this.string = string;
    }

}
