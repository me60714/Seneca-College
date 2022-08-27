/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

// Triangle class is an implement class from Shape interface
public class Triangle implements Shape{
    private double sideA;
    private double sideB;
    private double sideC;

    public Triangle(double sideA, double sideB, double sideC) throws TriangleException{
        // to avoid wrong values for three sides of a triangle,
        // one of a triangle's side must less than the sum of two other sides.
        if (sideA > 0 && sideB > 0 && sideC > 0 && (sideA + sideB > sideC) && (sideB + sideC) > sideA && (sideA + sideC) > sideB){
            this.sideA = sideA;
            this.sideB = sideB;
            this.sideC = sideC;
        }
        else
            throw new TriangleException("Invalid side(s)!");
    }

    public double getSideA() {
        return sideA;
    }

    public void setSideA(double sideA) throws TriangleException{
        if (sideA > 0)
            this.sideA = sideA;
        else
            throw new TriangleException("Invalid side(s)!");
    }

    public double getSideB() {
        return sideB;
    }

    public void setSideB(double sideB) throws TriangleException{
        if (sideB > 0)
            this.sideB = sideB;
        else
            throw new TriangleException("Invalid side(s)!");
    }

    public double getSideC() {
        return sideC;
    }

    public void setSideC(double sideC) throws TriangleException{
        if (sideC > 0)
            this.sideC = sideC;
        else
            throw new TriangleException("Invalid side(s)!");
    }

    @Override
    public double perimeter() {
        return (getSideA() + getSideB() + getSideC());
    }

    @Override
    public String toString() {
        return String.format("%s {s1=%s, s2=%s, s3=%s} perimeter = %g",this.getClass().getSimpleName(), this.getSideA(), this.getSideB(), this.getSideC(), this.perimeter());
    }
}
