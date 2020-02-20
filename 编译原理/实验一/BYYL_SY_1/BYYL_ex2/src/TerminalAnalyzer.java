import java.util.ArrayList;
public class TerminalAnalyzer
{
    private static String[] keywords = {"if", "then", "else", "while", "do"};
    private static Character[] operators = {'+', '-', '*', '/', '>', '<', '=', '(', ')', ';'};
    private static Character[] spaces = {' ', '\n', '\t'};
    private String code;
    private char[] codeChars;
    private int limitOfIdentifierLength;
    StringBuffer termialsBuffers = new StringBuffer();

    private class SingleTerminal
    {
        private String kind;
        private String attribute;

        public SingleTerminal(String kindIn, String attributeIn)
        {
            kind = kindIn;
            attribute = attributeIn;
        }

        public String getTerminalInfo()
        {
            return "<" + kind + "," + attribute + ">";
        }
    }

    public TerminalAnalyzer(String codeIn)
    {
        code = codeIn;
        codeChars = code.toCharArray();//开始处理源代码
        limitOfIdentifierLength = 200;
    }

    public String getTerminals()
    {
        int processingLocation = 0;
        String initState = "初态";
        ArrayList<String> states = new ArrayList<>();
        for (String tempStr; processingLocation < code.length(); processingLocation++)
        {//循环直到无法识别或代码结束，若代码结束时并非进行到无法识别的状态，则需要另外处理
            if (states.size() == 0)
                tempStr = scan(initState, processingLocation, states);
            else
                tempStr = scan(states.get(states.size() - 1), processingLocation, states);
            states.add(tempStr);//将目前状态添加到集合尾部
            if (tempStr.compareTo("无法继续识别") == 0)//目前无法继续识别
            {//开始回退状态，寻找最大匹配串
                int stateLocation = states.size() - 1;
                while (stateLocation >= 0)
                {//从最后一次识别开始寻找最长匹配终结符
                    if (states.get(stateLocation).split("_")[0].compareTo("终态") == 0)
                        break;
                    stateLocation--;
                }
                if (stateLocation == -1)
                {//没有匹配到任何终结符
                    boolean tempBoolean = false;
                    for (Character character :
                            spaces)
                        if (character.compareTo(codeChars[processingLocation - states.size() + 1]) == 0)
                        {
                            tempBoolean = true;
                            break;
                        }
                    if (tempBoolean)
                    {//如果是空格或者换行则继续下一个检查
                        states.clear();//清空状态记录数组
                        continue;
                    }
                    termialsBuffers.append("\n" + "此处结束了代码分析："
                            + codeChars[processingLocation - states.size() + 1]);//记录在返回的数据中
                    states.clear();//清空状态记录数组
                    break;//结束分析
                }
                else
                {//至少有一个最长匹配
                    StringBuffer tempBuffer = new StringBuffer();
                    for (int tempInt = 0; tempInt <= stateLocation; tempInt++)
                    {//得到匹配的字符
                        tempBuffer.append(codeChars[processingLocation - states.size() + 1 + tempInt]);
                    }
                    appendIn(states.get(stateLocation), tempBuffer.toString());//记录在返回的数据中
                    processingLocation = processingLocation - states.size() + stateLocation + 1;//调整处理位置
                    states.clear();//清空状态记录数组
                }
            }
        }
        processingLocation--;//矫正最后处理的位置
        if (states.size() != 0
                && states.get(states.size() - 1).split("_")[0].compareTo("终态") == 0)
        {//代码结束时是终态
            StringBuffer tempBuffer = new StringBuffer();
            for (int tempInt = states.size(); tempInt > 0; tempInt--)
            {//得到匹配的字符
                tempBuffer.append(codeChars[processingLocation - tempInt + 1]);
            }
            appendIn(states.get(states.size() - 1), tempBuffer.toString());//记录在返回的数据中
        }
        else
        {//代码结束时是间态
        }
        return termialsBuffers.toString();
    }

    private String scan(String state, int processingLocation, ArrayList<String> states)
    {
        //tempstr用于保存已读入的标识符或关键字字符
        //共有以下几种返回值
        //"初态"
        //"间态_0x"
        //"终态_标识符"，"终态_十进制0"，"终态_十进制正整数"，"终态_运算符和界符"
        //"终态_关键字"，"终态_八进制整数"，"终态_十六进制整数"
        //"无法继续识别"
        char processingChar = codeChars[processingLocation];//得到当前处理位置的字符
        switch (state)
        {
            case "初态"://初态
                if (Character.isLetter(processingChar))
                {//开头是一个字母，则先匹配为标识符Q
                    return "终态_标识符";
                }
                if (processingChar == '0')
                {//开头是阿拉伯数字0，则先匹配为十进制0
                    return "终态_十进制0";
                }
                if (Character.isDigit(processingChar))
                {//开头是不包括0的阿拉伯数字，则先匹配为十进制正整数
                    return "终态_十进制正整数";
                }
                boolean tempBoolean = false;
                for (Character c :
                        operators)
                {
                    if (c.compareTo(processingChar) == 0)
                    {
                        tempBoolean = true;
                        break;
                    }
                }
                if (tempBoolean)
                {//是一个运算符或界符，则先匹配为运算符和界符
                    return "终态_运算符和界符";
                }
                return "无法继续识别";//无法继续识别
            case "终态_标识符"://标识符的终态，表示首字符是字母，之后的字符是字母或数字
                //直接当做关键字处理
            case "终态_关键字"://关键字的终态，表示是一个关键字之一
                if (Character.isLetterOrDigit(processingChar))
                {
                    char tempChars[] = new char[processingLocation + 1-(processingLocation - states.size())];
                    code.getChars(processingLocation - states.size(), processingLocation + 1
                            , tempChars, 0);
                    String tempStr = String.valueOf(tempChars);//得到当前需要比较的标识符
                    boolean tempBool = false;
                    for (int i = 0; i < keywords.length; i++)
                        if (tempStr.compareTo(keywords[i]) == 0)
                        {
                            tempBool = true;//如果等同于任何一个关键字
                            break;
                        }
                    if (tempBool)
                    {//目前匹配为一个关键字
                        return "终态_关键字";
                    }
                    else//目前匹配为一个标识符
                        return "终态_标识符";
                }
                else
                    return "无法继续识别";//无法继续识别
            case "终态_十进制0"://十进制0的终态，表示单个数字0
                if (processingChar >= '1'
                        && processingChar <= '7')
                {//目前匹配为八进制整数
                    return "终态_八进制整数";
                }
                if (processingChar == 'x')
                {//该终结符的前两个字符为0x
                    return "间态_0x";
                }
                return "无法继续识别";//无法继续识别
            case "间态_0x"://间态，表示正在识别的终结符前两个字符为0x
            case "终态_十六进制整数"://终态，表示是十六进制数字
                if (Character.isDigit(processingChar)
                        || (processingChar <= 'e' && processingChar >= 'a'))
                    return "终态_十六进制整数";//还是十六进制数字
                else
                    return "无法继续识别";//无法继续识别
            case "终态_八进制整数"://终态，表示是八进制数字
                if (processingChar <= '7'
                        && processingChar >= '1')
                {//目前匹配为八进制整数
                    return "终态_八进制整数";
                }
                return "无法继续识别";//无法继续识别
            case "终态_十进制正整数"://终态，表示大于0的十进制数字
                if (Character.isDigit(processingChar))
                {//目前匹配为大于0的十进制数字
                    return "终态_十进制正整数";
                }
                else
                    return "无法继续识别";//无法继续识别
            case "终态_运算符和界符"://终态，表示运算符和界符+-*/><=();之一
                return "无法继续识别";//无法继续识别
            default:
                return "无法继续识别";//无法继续识别
        }
    }

    private void appendIn(String stateIn, String dataIn)
    {//将单个识别结果处理后连接到返回字符串中
        String state = new String();
        String data = new String();
        int indentation = dataIn.length()/4;
        switch (stateIn)
        {//"终态_标识符"，"终态_十进制0"，"终态_十进制正整数"，"终态_运算符和界符"
            //"终态_关键字"，"终态_八进制整数"，"终态_十六进制整数"
            case "终态_标识符":
                state = "\t" + "0" + "\t".repeat(3);
                data = "\t" + dataIn + "\t".repeat(3-indentation);
                break;
            case "终态_十进制0":
            case "终态_十进制正整数":
                state = "\t" + "1" + "\t".repeat(3);
                data = "\t" + dataIn + "\t".repeat(3-indentation);
                break;
            case "终态_运算符和界符":
                state = "\t" + dataIn + "\t".repeat(3);
                data = "\t" + "\t".repeat(3-indentation);
                break;
            case "终态_关键字":
                state = "\t" + dataIn + "\t".repeat(3-indentation);
                data = "\t" + dataIn + "\t".repeat(3-indentation);
                break;
            case "终态_八进制整数":
                state = "\t" + "2" + "\t".repeat(3);
                data = "\t" + dataIn + "\t".repeat(3-indentation);
                break;
            case "终态_十六进制整数":
                state = "\t" + "3" + "\t".repeat(3);
                data = "\t" + dataIn + "\t".repeat(3-indentation);
                break;
            default:
                break;
        }
        SingleTerminal tempSingleTerminal = new SingleTerminal(state, data);
        termialsBuffers.append("\n" + tempSingleTerminal.getTerminalInfo());
    }
}
