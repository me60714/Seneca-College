/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.rmi.RemoteException;

public class CarImpl extends java.rmi.server.UnicastRemoteObject implements CarInterface{

    public CarImpl() throws java.rmi.RemoteException{
        super();
    }

    @Override
    public String CarRegister(Car car) throws RemoteException {
        return " " + car.hashCode() + " ";
    }
}
