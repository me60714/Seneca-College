/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CarServer {

    public CarServer() {
        try {

            CarInterface obj = new CarImpl();
            Registry registry = LocateRegistry.createRegistry(1099);
            registry.rebind("CarRegister", obj);
            System.out.println("CarRegister bound in registry");

        } catch (Exception e) {
            System.err.println("Problem: " + e);
            System.exit(1);
        }
    }

    public static void main(String args[]) {
        new CarServer();
        System.out.println("CarRegister is running");
    }
}
