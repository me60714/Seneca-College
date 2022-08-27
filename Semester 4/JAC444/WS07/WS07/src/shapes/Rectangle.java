/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

// Rectangle class extends Parallelogram class, it inherits the methods from Parallelogram class.
public class Rectangle extends Parallelogram{
    public Rectangle(double width, double height) throws ParallelogramException {
        super(width, height);
    }

    // Task 4 from ws7, create an object of an interface that can calculate the area of a shape using lambda expressions
    public ShapeArea rectangleArea = () -> this.getWidth()*this.getHeight();

    // adding getArea from task4 WS7
    @Override
    public String toString() {
        return String.format( "%s {w=%s, h=%s} perimeter = %g, area = %g", this.getClass().getSimpleName(), this.getWidth(), this.getHeight(), this.perimeter(), rectangleArea.getArea());
    }
}
