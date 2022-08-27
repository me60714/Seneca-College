/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

package shapes;

import java.io.*;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        final String fileName = "shapes.txt";
        int fileLines = 0;
        int shapesCounter = 0;
        Shape[] shapes;
        String s;

        //first counting how many lines in the "shapes.txt" file, and assign it to the Shape array.
        try{
            File file = new File(fileName);
            long fileLength = file.length();
            LineNumberReader lineNumberReader = new LineNumberReader(new FileReader(file));
            lineNumberReader.skip(fileLength);
            fileLines = lineNumberReader.getLineNumber();
            lineNumberReader.close();
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
        shapes = new Shape[fileLines];

        //task 1
        System.out.println("------->JAC444 Workshop 7<-------");
        System.out.println("------->Task 4 ... <-------");

        // this try and catch code snippet is from WS03&04 instruction
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            while ((s = br.readLine()) != null) {
                String[] tokens = s.split(",");

                // compare if each line's text equal to any of these shapes or not
                // if it finds the match, assign that new shape to the new index of shape array
                if (Objects.equals(tokens[0], "Parallelogram") && tokens.length == 3){
                    try {
                        shapes[shapesCounter] = new Parallelogram(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
                        shapesCounter++;
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                }
                else if (Objects.equals(tokens[0], "Rectangle") && tokens.length == 3){
                    try {
                        shapes[shapesCounter] = new Rectangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
                        shapesCounter++;
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                }
                else if (Objects.equals(tokens[0], "Square") && tokens.length == 2){
                    try {
                        shapes[shapesCounter] = new Square(Double.parseDouble(tokens[1]));
                        shapesCounter++;
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                } else if (Objects.equals(tokens[0], "Circle") && tokens.length == 2){
                    try {
                        shapes[shapesCounter] = new Circle(Double.parseDouble(tokens[1]));
                        shapesCounter++;
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                } else if (Objects.equals(tokens[0], "Triangle") && tokens.length == 4){
                    try {
                        shapes[shapesCounter] = new Triangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]), Double.parseDouble((tokens[3])));
                        shapesCounter++;
                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }

        System.out.println();
        System.out.println(shapesCounter + " shapers are created:");
        for (Shape shape : shapes) {
            if (shape != null) {
                System.out.println(shape);
                System.out.println();
            }
        }
    }
}