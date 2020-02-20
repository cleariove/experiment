import java.io.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        File file = new File("C:\\Users\\StephenHe\\Desktop\\chorme下载\\BYYL_ex2\\program2.txt");//定义一个file对象，用来初始化FileReader
        FileReader reader = new FileReader(file);//定义一个fileReader对象，用来初始化BufferedReader
        BufferedReader bufferedReader = new BufferedReader(reader);//new一个BufferedReader对象，将文件内容读取到缓存
        StringBuilder stringBuilder = new StringBuilder();//定义一个字符串缓存，将字符串存放缓存中
        String string = "";
        while ((string =bufferedReader.readLine()) != null) {//逐行读取文件内容，不读取换行符和末尾的空格
            stringBuilder.append(string + "\n");//将读取的字符串添加换行符后累加存放在缓存中
            System.out.println(string);
        }
        bufferedReader.close();
        String str = stringBuilder.toString();
        TerminalAnalyzer terminalAnalyzer = new TerminalAnalyzer(str);
        System.out.println(terminalAnalyzer.getTerminals());
    }
}
