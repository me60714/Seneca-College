/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

import java.util.*;
import java.util.stream.Collectors;

public class StudentProcess {
    // create an array of Students
    private static Student[] students = {
            new Student("Jack", "Smith", 50.0, "IT"),
            new Student("Aaron", "Johnson", 76.0, "IT"),
            new Student("Maaria", "White", 35.8, "Business"),
            new Student("John", "White", 47.0, "Media"),
            new Student("Laney", "White", 62.0, "IT"),
            new Student("Jack", "Jones", 32.9, "Business"),
            new Student("Wesley", "Jones", 42.89, "Media")
    };

    public static void main(String[] args){

        List<Student> studentList = new ArrayList<>(Arrays.asList(students));
/**
        // task 1
        System.out.println("Task 1:\n");
        System.out.println("Complete Student list:");
        studentList.forEach(System.out::println);
        System.out.println("\n");

        // task 2
        System.out.println("Task 2:\n");
        System.out.println("Students who got 50.0-100.0 sorted by grade:");
        studentList.stream().filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
                .sorted(Comparator.comparing(Student::getGrade))
                .forEach(System.out::println);
        System.out.println("\n");

        // task 3
        System.out.println("Task 3:\n");
        System.out.println("First Student who got 50.0-100.0:");
        System.out.println(studentList.stream().filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
                .findFirst().get());
        System.out.println("\n");

        // task 4
        System.out.println("Task 4:\n");
        System.out.println("Students in ascending order by last name then first:");
        studentList.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName))
                .forEach(System.out::println);
        System.out.println();
        System.out.println("Students in descending order by last name then first:");
        studentList.stream()
                .sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName).reversed())
                .forEach(System.out::println);
        System.out.println("\n");

        // task 5
        System.out.println("Task 5:\n");
        System.out.println("Unique Student last names:");
        studentList.stream().map(Student::getLastName).distinct().sorted().forEach(System.out::println);
        System.out.println("\n");
*/
        System.out.println("Workshop 9:");
        System.out.println("-----------------------------------------------------------");


        // task 6
        System.out.println("Task 6:\n");
        System.out.println("Student names in order by last name then first name:");
        studentList.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName))
                .map(Student::getName).forEach(System.out::println);
        System.out.println("\n");

        // task 7
        System.out.println("Task 7:\n");
        System.out.println("Students by department");
        Map<String, List<Student>> temp = studentList.stream().collect(Collectors.groupingBy(Student::getDepartment));
        temp.forEach((k,v) -> {
            System.out.println(k);
            v.forEach(s -> System.out.println("\t" + s));
        });
        System.out.println("\n");

        // task 8
        System.out.println("Task 8:\n");
        System.out.println("Count of Students by department:");
        Map<String, Long> count = studentList.stream().sorted(Comparator.comparing(Student::getDepartment))
                .collect(Collectors.groupingBy(Student::getDepartment, Collectors.counting()));
        count = new TreeMap<>(count);
        count.forEach((k,v) -> System.out.println(k + " has " + v + " student(s)"));
        System.out.println("\n");

        // task 9
        System.out.println("Task 9:\n");
        System.out.print("Sum of Student's grades: ");
        double sum = studentList.stream().mapToDouble(Student::getGrade).sum();
        System.out.println(sum);
        System.out.println("\n");

        // task 10
        System.out.println("Task 10:\n");
        System.out.print("Average of Students' grades: ");
        double average = studentList.stream().mapToDouble(Student::getGrade).average().getAsDouble();
        System.out.println(String.format("%.2f", average));

        System.out.println("\n");
    }
}
