/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package ws6;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class StudentOutputFrame extends JFrame {
    private JLabel titleLabel;
    private JLabel numOFStudentLabel;
    private JTextArea studentsInfoTextArea;
    private JButton exitButton;
    private JPanel displayPanel;

    public StudentOutputFrame(){
        super("Students Info Display");
        displayPanel = new JPanel();
        setContentPane(displayPanel);
        displayPanel.setLayout(new BoxLayout(displayPanel, BoxLayout.Y_AXIS));
        displayPanel.setBorder(new EmptyBorder(10, 20, 10, 20));
        titleLabel = new JLabel("Students Info: ");
        titleLabel.setHorizontalTextPosition(SwingConstants.LEFT);
        displayPanel.add(titleLabel);

        ArrayList<Student> students;
        int numOfStudent = 1;

        try{
            // Read the file
            FileInputStream fis = new FileInputStream("students.out");
            ObjectInputStream ois = new ObjectInputStream(fis);

            // Create Student object from file.out
            students = (ArrayList<Student>)ois.readObject();

            // Display the students to the JTextArea
            if (students != null){
                for(Student student : students){
                    studentsInfoTextArea = new JTextArea(student.toString());
                    studentsInfoTextArea.setEditable(false);

                    numOFStudentLabel = new JLabel("Student " + numOfStudent);

                    displayPanel.add(numOFStudentLabel);
                    displayPanel.add(studentsInfoTextArea);
                    numOfStudent++;
                }
            }
            // Close file input stream
            ois.close();
            fis.close();
        }catch(Throwable err){
            System.err.println(err);
        }

        exitButton = new JButton("Exit");
        displayPanel.add(exitButton);
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}
