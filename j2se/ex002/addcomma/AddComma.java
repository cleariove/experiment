package ex002.addcomma;


import java.util.ArrayList;

public class AddComma
{
    //用于存放已经在单词前面添加过逗号的单词
    private StringBuffer stringsBeforeComma;
    //用于存放已经在单词后面添加过逗号的单词
    private StringBuffer stringsLaterComma;
    private StringBuffer string;
    //用于存放已经处理过该位置的逗号的位置信息
    private ArrayList<Integer> arrayList = new ArrayList<>();
    public StringBuffer getString()
    {
        return string;
    }



    public AddComma()
    {
        stringsBeforeComma = new StringBuffer();
        stringsLaterComma = new StringBuffer();
    }

    public AddComma(StringBuffer string)
    {
        stringsBeforeComma = new StringBuffer();
        stringsLaterComma = new StringBuffer();
        this.string = string;
    }
    public void addLaterComma(int location,GetLocation getLocation)
    //在该句出现的相同单词后面添加逗号
    {
        //得到这个单词添加逗号的位置
        int addLaterLocation = getLocation.laterLocation(getLocation.getPreviousWord(location), 0);
        while (addLaterLocation != -1)
        //只要该句中还有这个单词就继续遍历下去，不合法的添加位置已经在前面剔除
        {
            string.replace(addLaterLocation, addLaterLocation + 1, ",");
            addLaterLocation = getLocation.laterLocation(getLocation.getPreviousWord(location), addLaterLocation);
        }
    }

    public void addPreviousComma(int location,GetLocation getLocation)
    //在该句出现的相同单词前面添加逗号
    {
        //得到这个单词添加逗号的位置
        int addPreviousComma = getLocation.previousLocation(getLocation.getLaterWord(location), 0);
        while (addPreviousComma != -1)
        //只要该句中还有这个单词就继续遍历下去，不合法的添加位置已经在前面剔除
        {
            string.replace(addPreviousComma - 1, addPreviousComma, ",");
            addPreviousComma = getLocation.previousLocation(getLocation.getLaterWord(location), addPreviousComma);
        }
    }

    public void addAllComma()
    {
        GetLocation getLocation = new GetLocation(this.string);
        int location = getLocation.getCommaLocation(0);
        while(location != -1)
        //只要遍历该句子让所有的逗号都已经存在逗号数组列表中就说明该句子添加不了逗号了，期间只要添加过新的逗号就重新遍历一次
        {
            if(!arrayList.contains(location))
            //如果这个逗号位置没包括进来的话就先把这个逗号的前后单词按需加上逗号
            {
                if(stringsBeforeComma.indexOf(getLocation.getPreviousWord(location)) == -1)
                //如果该单词前面没添加过逗号才添加
                {
                    addPreviousComma(location,getLocation);
                    //将该单词添加进字符串
                    stringsBeforeComma = stringsBeforeComma.append(getLocation.getLaterWord(location));
                }
                if(stringsLaterComma.indexOf(getLocation.getLaterWord(location)) == -1)
                {
                    addLaterComma(location,getLocation);
                    stringsLaterComma = stringsLaterComma.append(getLocation.getPreviousWord(location));
                }
                //将该位置加入list里并重新开始找逗号
                arrayList.add(location);
                location = getLocation.getCommaLocation(0);
            }
            else
                location = getLocation.getCommaLocation(location + 1);
        }
    }

}
