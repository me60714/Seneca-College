/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.io.Serializable;

public class Car implements Serializable {
    private String model;
    private String color;
    private double mileage;
    private String plate;

    public Car(String model, String color, double mileage) {
        this.model = model;
        this.color = color;
        this.mileage = mileage;
        this.plate = "undefined";
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getMileage() {
        return mileage;
    }

    public void setMileage(double mileage) {
        this.mileage = mileage;
    }

    public String getPlate() {
        return plate;
    }

    public void setPlate(String plate) {
        this.plate = plate;
    }

    @Override
    public String toString(){
        return "Model: " + getModel() + "\nColor: " + getColor() + "\nMileage: " + getMileage() + "\nPlate: " + getPlate();
    }
}
