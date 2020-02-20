package exercise.stream;


import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Stream
{
    private List<Integer> list = new ArrayList<>();

    public Stream()
    {
    }

    public Stream(List<Integer> list)
    {
        this.list = list;
    }

    public void creat()
    {
        for(int i = 0;i < 20;i++)
        {
            list.add(new Random().nextInt(100));
        }
    }

    public void showAll()
    {
        list.stream().sorted().forEach(System.out::println);
    }

    public void showGreaterThanFifty()
    {
        //list.stream().sorted().dropWhile(a -> a < 50).forEach(System.out::println);
    }

    public void show()
    {
        list.stream().sorted().map(a -> a = a > 80 ? a - 2 * a : a).forEach(System.out::println);
    }
    public List<Integer> getList()
    {
        return list;
    }

    public void setList(List<Integer> list)
    {
        this.list = list;
    }
}
