/**
 * Course Section: JAC444NAA
 * Student Name  : Wei-Chih Kao
 * Student ID    : 158000190
 */

public class Withdraw extends Thread{
    private StrangeBank bank;

    public Withdraw(StrangeBank bank){
        super();
        this.bank = bank;
    }

    public void run(){

        for(int i = 0; i < 6; i++){
            synchronized (bank){
                bank.withdraw();

                try{
                    Thread.sleep((int)(Math.random() * 1000));
                }catch (InterruptedException e){
                    System.err.println(e.getMessage());
                }
            }
        }
    }
}
