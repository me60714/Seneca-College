/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package ws5_6;

import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

/**
 * And finally, in the third class of this project, you need to read those student objects from the file,
 * and then show their info in the console, to verify that they had been saved (and serialized) correctly.
 */

public class StudentDeserial extends Student{

    public static void main(String[] args){
        int numOfStudent = 1;
        ArrayList<Student> students;

        try{
            // Read the file
            FileInputStream fis = new FileInputStream("file.out");
            ObjectInputStream ois = new ObjectInputStream(fis);

            // Create Student object from file.out
            students = (ArrayList<Student>)ois.readObject();

            // Print student info in the console
            if(students != null){
                for (Student student : students){
                    System.out.println("Student " + numOfStudent++);
                    System.out.println("Student ID: " + student.getStdID());
                    System.out.println("Student first name: " + student.getFirstName());
                    System.out.println("Student last name: " + student.getLastName());
                    System.out.println("Student courses: " + student.getCourses());
                    System.out.println();
                }
            }

            // Close file input stream
            ois.close();
            fis.close();

        } catch (Throwable e){
            System.err.println(e);
        }
    }

}
