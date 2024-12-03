// Develop a JAVA program to create an Outer class with a function display.
// Create another class inside the Outer class named Inner with a function called display and call the two functions in the main class.

class Outer {
    public static void display(){
        System.out.println("Inside the Outer class");
    }

    class Inner {
        public static void display(){
            System.out.println("Inside the Inside class");
        }
    }
}

public class MainClass{
    public static void main(String[] args){
        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();
    }
}