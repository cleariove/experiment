package ex002.student;

import java.time.LocalDate;
import java.util.Objects;

public class Student implements Comparable<Student> {

    private String id;
    private String name;
    private LocalDate birth;

    public Student() {
    }

    public Student(String id, String name, LocalDate birth) {
        this.id = id;
        this.name = name;
        this.birth = birth;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public LocalDate getBirth() {
        return birth;
    }

    public int getAge(){
        return LocalDate.now().getYear()-birth.getYear();
    }

    public void setBirth(LocalDate birth) {
        this.birth = birth;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return Objects.equals(getId(), student.getId());
    }

    @Override
    public int hashCode() {

        return Objects.hash(getId());
    }

    @Override
    public String toString() {
        return "Student{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", birth=" + birth +
                "age = "+getAge()+"\n";
    }

    @Override
    public int compareTo(Student o) {
        return this.id.compareTo(o.id);
    }
}