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

    @Override
    public String toString() {
        return String.format( "%s {s=%s} perimeter = %g", this.getClass().getSimpleName(), this.getWidth(), this.perimeter());
    }
}
