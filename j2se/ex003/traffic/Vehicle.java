package ex003.traffic;

public class Vehicle
{
    private double speed;
    private double size;

    public Vehicle()
    {
    }

    public Vehicle(double speed, double size)
    {
        this.speed = speed;
        this.size = size;
    }

    public void move()
    {
        System.out.println("Move!");
    }

    public void speedUp()
    {
        setSpeed(this.speed + 10);
    }

    public void speedDown()
    {
        setSpeed(this.speed - 10);
    }

    public double getSpeed()
    {
        return speed;
    }

    public void setSpeed(double speed)
    {
        this.speed = speed;
    }

    public double getSize()
    {
        return size;
    }

    public void setSize(double size)
    {
        this.size = size;
    }

    @Override
    public String toString()
    {
        return "Vehicle{" +
                "speed=" + speed +
                ", size=" + size +
                '}';
    }
}
