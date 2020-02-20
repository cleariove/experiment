package ex002.checksecret;

import java.util.Scanner;

public class TestCheck
{
    public static void main(String[] args)
    {
        System.out.println("请输入密码:");
        Scanner input = new Scanner(System.in);
        String secret = input.next();
        ValidPassword validPassword = new ValidPassword(secret);
        validPassword.isValidPassword();
    }
}
