/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package ws5_6;

import java.io.*;
import java.util.ArrayList;

/**
 * In the second class, you will need to enter some information for some student objects from the console
 * and save these student objects in a file.
 */

public class StudentSerial extends Student{
    private static Student student;
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args){

        ArrayList<Student> students = new ArrayList<Student>();
        String yOrN;

        try{
            do{
                student = new Student();
                // ID
                System.out.print("Enter Student ID: ");
                int studentID = Integer.parseInt(in.readLine());
                student.setStdID(studentID);

                // FirstName
                System.out.print("Enter Student First Name: ");
                String studentFirstName = in.readLine();
                student.setFirstName(studentFirstName);

                // Lastname
                System.out.print("Enter Student Last Name: ");
                String studentLastName = in.readLine();
                student.setLastName(studentLastName);

                // Courses
                System.out.print("Enter Student Courses Name(seperated by ','): ");
                String coursesName = in.readLine();
                String[] coursesArray = coursesName.split(",");
                for (String course : coursesArray){
                    student.setCourses(course);
                }

                students.add(student);

                do{
                    System.out.print("Add another student?(Y or N): ");
                    yOrN = in.readLine();
                    if (!yOrN.equals("Y") && !yOrN.equals("N") && !yOrN.equals("y") && !yOrN.equals("n")){
                        System.out.println("Invalid answer! Try again please!");
                    }
                }while(!yOrN.equals("Y") && !yOrN.equals("N") && !yOrN.equals("y") && !yOrN.equals("n"));

            }while(yOrN.equals("Y") || yOrN.equals("y"));

            // Write student object to file "file.out"
            FileOutputStream fos = new FileOutputStream("file.out");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(students);

            // Close streams
            oos.flush();
            fos.close();

            System.out.println("file saved");

        } catch (Throwable e){
            System.err.println(e);
        }
    }

}
