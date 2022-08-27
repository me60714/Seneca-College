/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

public class StrangeBank {
    private double balance;
    private String currency;

    // default constructor
    public StrangeBank(){
        balance = 0.0;
        currency = "";
    }

    // setters and getters
    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getCurrency() {
        return currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }

    public boolean hasMoney(){
        return getBalance() > 0;
    }

    // deposit method
    public synchronized void deposit(String currency){

        while (hasMoney() && getCurrency() != currency){
            try{
                System.err.println("Waiting for withdraw or deposit in same currency...");
                wait();
            } catch (InterruptedException e){
                System.err.println(e.getMessage());
            }
        }

        if (getCurrency() == currency){
            setBalance(this.balance += 1);
            setCurrency(currency);
        } else {
            setBalance(1);
            setCurrency(currency);
        }

        System.out.println("Deposit: 1.0 " + currency);
        System.out.println("The balance after deposit: " + getBalance() + " " + getCurrency());
        System.out.println();
        notify();
    }

    // withdraw method
    public synchronized void withdraw(){

        while (getBalance() == 0){
            try{
                System.err.println("The account is empty, waiting for deposit...");
                wait();
            }catch (InterruptedException e){
                System.err.println(e.getMessage());
            }
        }

        this.balance -= 1;
        System.out.println("Withdraw: 1.0 " + getCurrency());
        System.out.println("The balance after withdraw: " + getBalance() + " " + getCurrency());
        System.out.println();
        notify();
    }
}


