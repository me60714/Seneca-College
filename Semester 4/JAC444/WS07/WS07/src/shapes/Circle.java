/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

// Circle class is an implement class from Shape interface
public class Circle implements Shape{
    private double radius;

    public Circle(double radius) throws CircleException{
        if (radius > 0)
            this.radius = radius;
        else
            throw new CircleException("Invalid radius!");
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) throws CircleException{
        if (radius > 0)
            this.radius = radius;
        else
            throw new CircleException("Invalid radius!");
    }

    // Task 4 from ws7, create an object of an interface that can calculate the area of a shape using lambda expressions
    private ShapeArea circleArea = () -> this.getRadius() * this.getRadius() * Math.PI;

    @Override
    public double perimeter() {
        return Math.round((2*getRadius()*Math.PI) * 100000.0)/100000.0;
    }

    // adding getArea from task4 WS7
    @Override
    public String toString() {
        return String.format("%s {r=%s} perimeter = %g, area = %g",this.getClass().getSimpleName(), this.getRadius(), this.perimeter(), circleArea.getArea());
    }
}
