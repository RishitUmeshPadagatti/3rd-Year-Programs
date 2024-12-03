// public class Main extends Thread{
//     @Override
//     public void run(){
//         System.out.println("The code is running in the thread");
//     }
//     public static void main(String[] args){
//         Main thread = new Main();
//         thread.start();
//         System.out.println("The code is running outside the thread");
//     }
// }

// public class Main implements Runnable{
//     @Override
//     public void run(){
//         System.out.println("The code is running in the thread");
//     }
//     public static void main(String[] args){
//         Main obj = new Main();
//         Thread thread = new Thread(obj);
//         thread.start();
//         System.out.println("The code is running outside the thread");
//     }
// }

public class Main extends Thread{
    public static int amount = 0;

    public static void main(String[] args){
        Main thread = new Main();
        thread.start();

        while(thread.isAlive()){
            System.out.println("Waiting...");
        }

        System.out.println("Main: " + amount);
        amount++;
        System.out.println("Main: " + amount);
    }

    @Override
    public void run(){
        amount++;
    }
}