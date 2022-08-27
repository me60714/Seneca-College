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
        System.out.println("------->JAC 444 Assignment 1<-------");
        System.out.println("------->Task 1 ... <-------");

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
        // task 1
        System.out.println("...");
        System.out.println("This part done in WS03");
        System.out.println("...");
//        System.out.println();
//        System.out.println(shapesCounter + " shapers are created:");
//        for (Shape shape : shapes) {
//            if (shape != null) {
//                System.out.println(shape);
//                System.out.println();
//            }
//        }

        // task 2
        System.out.println("------->Task 2 ... <-------");

        // to find the smallest perimeter of triangles
        double smallestTriangle = 999;
        for (Shape shape : shapes){
            if (shape != null && shape instanceof Triangle){
                if(smallestTriangle > shape.perimeter())
                    smallestTriangle = shape.perimeter();
            }
        }
        // set all the triangles with the smallest perimeter to null
        for(int i = 0; i < shapesCounter; i++) {
            if(shapes[i] instanceof Triangle) {
                if( shapes[i].perimeter() == smallestTriangle) {
                    shapes[i] = null;
                }
            }
        }
        // to find the biggest perimeter of circles
        double biggestCircle = 0;
        for (Shape shape : shapes){
            if (shape != null && shape instanceof Circle){
                if (biggestCircle < shape.perimeter())
                    biggestCircle = shape.perimeter();
            }
        }
        // set all the circles with the biggest perimeter to null
        for (int i = 0; i < shapesCounter; i++){
            if (shapes[i] instanceof Circle){
                if (shapes[i].perimeter() == biggestCircle){
                    shapes[i] = null;
                }
            }
        }

        // print all the shapes
        for (Shape shape : shapes){
            if (shape != null){
                System.out.println(shape);
                System.out.println();
            }
        }

        // task 3
        System.out.println("------->Task 3 ... <-------");

        double sumOfParallelogram = 0;
        double sumOfTriangle = 0;

        for (Shape shape : shapes){
            if ((shape instanceof Parallelogram) && !(shape instanceof Rectangle) && !(shape instanceof Square)){
                sumOfParallelogram += shape.perimeter();
            }

            if (shape instanceof Triangle){
                sumOfTriangle += shape.perimeter();
            }
        }

        // print the sum of parallelogram and triangle
        System.out.println("Total perimeter of Parallelogram is: " + sumOfParallelogram);
        System.out.println("Total perimeter of Triangle is: " + sumOfTriangle);
    }
}