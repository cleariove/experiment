package ex002.student;

import java.util.Comparator;

public class SortById implements Comparator
{
    @Override
    public int compare(Object o1, Object o2)
    {
        return ((Student) o1).getId().compareTo(((Student) o2).getId());
    }
}
