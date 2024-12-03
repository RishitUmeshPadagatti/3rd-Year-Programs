// Develop a JAVA program to raise a custom exception (user defined exception) for DivisionByZero using try, catch, throw and finally

class DivisionByZeroException extends Exception{
    public DivisionByZeroException(String message){
        super(message);
    }
}

public class CustomExceptionExample{
    public static void main(String[] args){
        try{
            int numerator = 10;
            int denominator = 0;

            if (denominator==0){
                throw new DivisionByZeroException("Cannot divide by zero");
            }

            int result = numerator/denominator;
            System.out.println("Result: " + result);
        }
        catch(DivisionByZeroException e){
            System.out.println("Error: " + e.getMessage());
        }
        catch(ArithmeticException e){
            System.out.println("Error: " + e.getMessage());
        }
        finally{
            System.out.println("Finally block executed");
        }
    }
}