/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface CarInterface extends Remote {
    public String CarRegister(Car car) throws RemoteException;
}
