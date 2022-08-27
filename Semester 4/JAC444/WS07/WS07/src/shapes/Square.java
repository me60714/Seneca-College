/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

// Square class extends Rectangle class, it inherits the methods from Rectangle class.
public class Square extends Rectangle{
    public Square(double side) throws ParallelogramException {
        super(side, side);
    }

    // Task 4 from ws7, create an object of an interface that can calculate the area of a shape using lambda expressions
    public ShapeArea squareArea = () -> this.getWidth()*this.getWidth();

    // adding getArea from task4 WS7
    @Override
    public String toString() {
        return String.format( "%s {s=%s} perimeter = %g, area = %g", this.getClass().getSimpleName(), this.getWidth(), this.perimeter(), squareArea.getArea());
    }
}
