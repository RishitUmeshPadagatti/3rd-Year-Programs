// Develop a stack class to hold a maximum of 10 integers with suitable methods. Develop a JAVA main method to illustrate Stack Operations

public class Stack{
    private static final int max = 3;
    private static int[] stackArray;
    private static int top;

    public Stack(){
        stackArray = new int[max];
        top = -1;
    }

    private static void push(int element){
        if (top < max-1){
            stackArray[++top] = element;
            System.out.println("Pushed: " + element);
        }
        else{
            System.out.println("Stack Overflow");
        }
    }

    private static void pop(){
        if (top >= 0){
            int poppedElement = stackArray[top--];
            System.out.println("Popped Element: " + poppedElement);
        }
        else{
            System.out.println("Stack Underflow");
        }
    }

    private static void display(){
        if (top>=0){
            for (int i=top; i>=0; i--){
                System.out.println(stackArray[i]);
            }
        }
        else{
            System.out.println("No elements in the stack");
        }
    }

    public static void main(String[] args){
        Stack stack = new Stack();

        stack.pop();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();
        stack.push(40);
        stack.pop();
        stack.display();
    }
}