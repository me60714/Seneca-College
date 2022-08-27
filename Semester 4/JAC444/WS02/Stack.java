//student name: Wei-Chih Kao
//student ID  : 158000190

public class Stack {
    private final char[] arr;
    private int currentPosition;

    //constructor, use arrSize to initialize the array
    public Stack(int arrSize){
        arr = new char[arrSize];
        currentPosition = -1;
    }

    //to check if the stack is empty or not
    public boolean isEmpty(){
        return (currentPosition == -1);
    }

    //to check if the stack is full or not
    public boolean isFull(){
        return !(currentPosition < arr.length - 1);
    }

    //push single char to the array
    public void push(char ch){
        if (isFull())
            System.out.println("The stack is full!");
        else
            arr[++currentPosition] = ch;
    }

    //pop single char from the array
    public char pop(){
        char popChar = ' ';

        if (isEmpty())
            System.out.println("The stack is empty!");
        else
            popChar = arr[currentPosition--];

        return popChar;
    }
}
