// Develop a program to create a class MyThread in this calls a constructor, call the base class constructor, using super and start the thread
// The run method of the class starts after this. It can be observed that both main thread and created child thread are executed concurrently.

class MyThread extends Thread{
    public MyThread(String threadName){
        super(threadName);
        start();
    }

    @Override
    public void run(){
        try{
            for (int i=0; i<=5; i++){
                System.out.println(Thread.currentThread().getName() + ": Count - " + i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println(Thread.currentThread().getName() + " thread interrupted");
        }
        System.out.println(Thread.currentThread().getName() + " thread exiting");
    }
}

public class ThreadExample{
    public static void main(String[] args){
        MyThread thread = new MyThread("child");

        try{
            for (int i=1; i<=5; i++){
                System.out.println(thread.currentThread().getName() + ": Count - " + i);
                thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println(thread.currentThread().getName() + " thread interrupted");
        }
        System.out.println(thread.currentThread().getName() + " thread exiting");
    }
}