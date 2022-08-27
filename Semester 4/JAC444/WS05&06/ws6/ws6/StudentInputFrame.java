/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package ws6;

import javax.swing.*;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class StudentInputFrame extends JFrame {
    private JTextField studentIDFiled;
    private JTextField studentFirstNameField;
    private JTextField studentLastNameField;
    private JTextField studentCoursesField;
    private JLabel studentIDLabel;
    private JLabel studentFirstNameLabel;
    private JLabel studentLastNameLabel;
    private JLabel studentCoursesLabel;
    private JButton addButton;
    private JButton finishButton;

    private Student student;
    private ArrayList<Student> students;

    // StudentInputFrame constructor
    public StudentInputFrame(){
        super("Students Info Input");
        setLayout(new FlowLayout());
        student = new Student();
        students = new ArrayList<Student>();

        // set the labels and the fields
        studentIDLabel = new JLabel("Student ID: ");
        studentIDLabel.setToolTipText("This is student ID field");
        studentIDFiled = new JTextField(15);
        add(studentIDLabel);
        add(studentIDFiled);

        studentFirstNameLabel = new JLabel("First Name: ");
        studentFirstNameLabel.setToolTipText("This is first name field");
        studentFirstNameField = new JTextField(15);
        add(studentFirstNameLabel);
        add(studentFirstNameField);

        studentLastNameLabel = new JLabel("Last Name : ");
        studentLastNameLabel.setToolTipText("This is last name field");
        studentLastNameField = new JTextField(15);
        add(studentLastNameLabel);
        add(studentLastNameField);

        studentCoursesLabel = new JLabel("Courses(separate by ',')   : ");
        studentCoursesLabel.setToolTipText("This is courses field");
        studentCoursesField = new JTextField(20);
        add(studentCoursesLabel);
        add(studentCoursesField);

        // set the add button to add student into the students arraylist
        addButton = new JButton("Add this student");
        add(addButton);
        // create new ButtonHandler for button event handling use anonymous inner class
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String studentID = studentIDFiled.getText();
                try{
                    int stdID = Integer.parseInt(studentID);
                    student.setStdID(stdID);
                    student.setFirstName(studentFirstNameField.getText());
                    student.setLastName(studentLastNameField.getText());
                    student.setCourses(studentCoursesField.getText());
                    students.add(student);
                    empty();
                }catch(Throwable err){
                    System.err.println(err);
                }
            }
        });

        // set the finish button and write student info into file
        finishButton = new JButton("Finish");
        add(finishButton);
        // create new ButtonHandler for button event handling use anonymous inner class
        finishButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try{
                    // Write student object to file "file.out"
                    FileOutputStream fos = new FileOutputStream("students.out");
                    ObjectOutputStream oos = new ObjectOutputStream(fos);
                    oos.writeObject(students);

                    // Close streams
                    oos.flush();
                    fos.close();
                }catch(Throwable err){
                    System.err.println(err);
                }
            }
        });
    } // end StudentInput constructor

    // set all the field to empty
    public void empty(){
        studentIDFiled.setText("");
        studentFirstNameField.setText("");
        studentLastNameField.setText("");
        studentCoursesField.setText("");
        student = new Student();
    }




}
