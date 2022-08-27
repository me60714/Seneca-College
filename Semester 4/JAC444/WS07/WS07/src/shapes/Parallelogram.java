/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

// Parallelogram class is an implement class from Shape interface
public class Parallelogram implements Shape{
    private double width;
    private double height;

    public Parallelogram(double width, double height) throws ParallelogramException{

        if (width > 0 && height > 0){
            this.width = width;
            this.height = height;
        }
        else{
            throw new ParallelogramException("Invalid side!");
        }
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) throws ParallelogramException{
        if (width > 0)
            this.width = width;
        else
            throw new ParallelogramException("Invalid side!");
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) throws ParallelogramException{
        if (height > 0)
            this.height = height;
        else
            throw new ParallelogramException("Invalid side!");
    }

    @Override
    public double perimeter() {
        double perimeter = (getHeight() + getWidth()) * 2;
        return Math.round(perimeter * 1000000.0)/1000000.0;
    }

    @Override
    public String toString() {
        return String.format( "%s {w=%s, h=%s} perimeter = %g", this.getClass().getSimpleName(), this.getWidth(), this.getHeight(), this.perimeter());
    }
}
