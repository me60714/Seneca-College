// Course    : JAC444
// Section   : NAA
// Name      : Wei-Chih Kao
// Student ID: 158000190
public class Main {
    public static void main(String[] args) {
        // set the constant value (number of row)
        final int NUM_ROW = 8;

        // the outside for loop, decide how many rows
        for (int i = 1; i <= NUM_ROW; i++)
        {
            // In the i row, j == how many spaces. Because the biggest number 128 has 3 digits,
            // The space for one number is 4.
            for (int j = 1; j <= 4*(NUM_ROW - i); j++){
                System.out.print(" ");
            }

            // The left part numbers 1, 2, 4, 8...128,
            // each number use "%4d" to format with a minimum field width of 4 characters.
            // use Math.pow to calculate the power of 2 and transfer to integer.
            for (int k = 1; k <= i; k++){
                System.out.printf("%4d", (int)Math.pow(2, k-1));
            }

            // The right part numbers, same idea but from the second biggest number to 1.
            for (int m = i - 1; m >= 1; m--){
                System.out.printf("%4d", (int)Math.pow(2, m-1));
            }

            // make new line
            System.out.println();
        }
    }
}