package ex002.student;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;

public class TestStudent
{
    public static void main(String[] args)
    {
        ArrayList<Student> students = new ArrayList<>();
        students.add(new Student("001","zhangsan",LocalDate.now()));
        students.add(new Student("003","LISI",LocalDate.now()));
        students.add(new Student("002","abc",LocalDate.now()));
        System.out.println(students.toString());
        Collections.sort(students);
        System.out.println(students);
    }
}
