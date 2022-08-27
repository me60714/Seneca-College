/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.text.DecimalFormat;

public class Student {

    // four fields
    private String firstName;
    private String lastName;
    private double grade;
    private String department;

    // constructor
    Student(String firstName, String lastName, double grade, String department){
        if(!firstName.isEmpty() && !lastName.isEmpty() && grade >= 0.0 && !department.isEmpty()){
            setFirstName(firstName);
            setLastName(lastName);
            setGrade(grade);
            setDepartment(department);
        }
    }

    // setters
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    // getters
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getName(){
        return getFirstName() + " " + getLastName();
    }

    public double getGrade() {
        return grade;
    }

    public String getDepartment() {
        return department;
    }

    // override toString
    @Override
    public String toString() {
        return getFirstName() + "\t" + getLastName() + "\t\t" + new DecimalFormat("0.00").format(getGrade()) + "\t" + getDepartment();
    }

    // equals
    public boolean equals(Student stu) {
        boolean equals = false;
        if (this.getFirstName() == stu.getFirstName() && this.getLastName() == stu.getLastName()
                && this.getGrade() == stu.getGrade() && this.getDepartment() == stu.getDepartment())
            equals = true;

        return equals;
    }
}
