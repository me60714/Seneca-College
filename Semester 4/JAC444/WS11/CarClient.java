/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class CarClient {

    public static void main(String[] args) {
        try {
            Car car = new Car("Subaru", "Sliver", 200.50);
            System.out.println("Car info:");
            System.out.println(car.toString());

            CarInterface carInterface = (CarInterface) Naming.lookup("rmi://localhost:1099/CarRegister");
            car.setPlate(carInterface.CarRegister(car));
            System.out.println();
            System.out.println("Car plate: " + car.getPlate());
            System.out.println("Cat info updated...");
            System.out.println(car.toString());

        } catch(MalformedURLException murle) {
            System.out.println("MalformedURLException");
            System.out.println(murle);
        } catch (RemoteException re) {
            System.out.println("RemoteException");
            System.out.println(re);
        } catch (NotBoundException nbe) {
            System.out.println("NotBoundException");
            System.out.println(nbe);
        } catch (ArithmeticException ae) {
            System.out.println("ArithmeticException");
            System.out.println(ae);
        }
    }
}
