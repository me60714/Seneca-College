/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package ws5_6;

import java.io.Serializable;
import java.util.ArrayList;

/**
 * This class has fields such as stdID (int), firstName (String), lastName (String), and courses (an array or preferably
 * an ArrayList which contains the names of the courses the student currently has). Please provide constructors, getters,
 * and setters, where appropriate.
 */

public class Student implements Serializable {
    private int stdID;
    private String firstName;
    private String lastName;
    private ArrayList<String> courses = new ArrayList<String>();

    // Constructors
    public Student(){}

    public Student(int StdID, String firstName, String lastName, ArrayList<String> courses){
        this.stdID = stdID;
        this.firstName = firstName;
        this.lastName = lastName;
        this.courses = courses;
    }

    // Setters
    public void setStdID(int stdID) throws Exception{
        try{
            if(stdID >= 0){
                this.stdID = stdID;
            } else{
                throw new Exception();
            }
        }
        catch(Exception e){
            throw new Exception("Invalid student ID!");
        }
    }

    public void setFirstName(String firstName) throws Exception{
        if (!firstName.isEmpty()){
            this.firstName = firstName;
        } else{
            throw new Exception("Invalid student first name!");
        }
    }

    public void setLastName(String lastName) throws Exception{
        if (!lastName.isEmpty()){
            this.lastName = lastName;
        } else{
            throw new Exception("Invalid student last name!");
        }
    }

    public void setCourses(String courses) throws Exception{
        if (!courses.isEmpty()){
            this.courses.add(courses);
        } else{
            throw new Exception("Invalid course name!");
        }
    }

    // Getters
    public int getStdID() {
        return stdID;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public ArrayList<String> getCourses() {
        return courses;
    }

    @Override
    public String toString(){
        return String.format("Student ID: %s%n, Student Name: %s %s%n, Student Courses: %s%n", this.getStdID(), this.getFirstName(), this.getLastName(), this.getCourses());
    }
}
