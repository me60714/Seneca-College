/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

public class Main {
    public static void main(String[] args) {

        String[] currency = {"Dollar(s)", "Euro(s)", "Euro(s)", "Pound(s)", "Pound(s)", "Pound(s)"};
        StrangeBank bank = new StrangeBank();

        Thread deposit = new Deposit(bank, currency);
        deposit.start();

        Thread withdraw = new Withdraw(bank);
        withdraw.start();
    }
}