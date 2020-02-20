package ex003.traffic;

public class TestVehicle
{
    public static void main(String... args)
    {
        Vehicle car = new Vehicle(100,6);

        car.move();

        System.out.println(car.toString());

        car.speedUp();

        System.out.println("Speed Up!" + car.toString());

        car.speedDown();

        System.out.println("Speed Down!" + car.toString());
    }
}
