package ex001.print;

public class PrintChar
{
    public static void main(String[] args)
    {
        char[] char1 = Character.toChars(0x1D307);
        String string = new String(char1);
        System.out.println(String.format("%5s%s%s%s%s%s%10s%10s%10s%13s",string,string,string,string,string,string,string,string,string,string));
        System.out.println(String.format("%9s%13s%4s%10s%7s%12s%4s",string,string,string,string,string,string,string));
        System.out.println(String.format("%5s%4s%12s%3s%3s%11s%4s%12s%3s%3s",string,string,string,string,string,string,string,string,string,string));
        System.out.println(String.format("%7s%s%10s%9s%12s%12s%8s",string,string,string,string,string,string,string));
    }
}
