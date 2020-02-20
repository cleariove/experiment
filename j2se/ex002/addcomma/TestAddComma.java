package ex002.addcomma;

import java.util.Scanner;

public class TestAddComma
{
    public static void main(String... args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入");
        StringBuffer stringBuffer = new StringBuffer(new String(input.nextLine()));
        AddComma addComma = new AddComma(stringBuffer);
        addComma.addAllComma();
        System.out.println("结果为"+addComma.getString());
    }
}