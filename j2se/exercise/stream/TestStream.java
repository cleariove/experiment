package exercise.stream;

import java.util.ArrayList;
import java.util.List;

public class TestStream
{
    public static void main(String... args)
    {
        List<Integer> list = new ArrayList<>();
        Stream stream = new Stream(list);
        stream.creat();
        System.out.println("输出全部");
        stream.showAll();
        System.out.println("输出大于50的");
        stream.showGreaterThanFifty();
        System.out.println("输出带负数");
        stream.show();
    }
}
