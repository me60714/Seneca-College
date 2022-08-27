/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

public class Deposit extends Thread{
    private StrangeBank bank;
    private String[] currency;

    public Deposit (StrangeBank bank, String[] currency){
        super();
        this.bank = bank;
        this.currency = currency;
    }

    public void run(){

        for (int i = 0; i < 6; i++){
            synchronized (bank){
                bank.deposit(currency[i]);

                try{
                    Thread.sleep((int)(Math.random() * 1000));
                }catch (InterruptedException e){
                    System.err.println(e.getMessage());
                }
            }
        }
    }
}
