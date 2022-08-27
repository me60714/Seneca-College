//student name: Wei-Chih Kao
//student ID  : 158000190

public class Palindrome {
    public static void main(String[] args){
        for (String str : args){
            if (isPalindrome(str))
                System.out.println(str + " is a palindrome!");
            else
                System.out.println(str + " is not a palindrome!");
        }
    }

    static boolean isPalindrome(String str){
        Stack stack = new Stack(str.length());
        boolean isPalindrome = true;

        // push string into stack
        for (char ch : str.toCharArray()){
            stack.push(ch);
        }

        // to check whether the first element in the stack is the same with the last element,
        // and the second element with the second last ... and so on.
        for (int i = 0; i < str.length(); i++){
            if(str.charAt(i) != stack.pop())
                isPalindrome = false;
        }

        return isPalindrome;
    }
}
