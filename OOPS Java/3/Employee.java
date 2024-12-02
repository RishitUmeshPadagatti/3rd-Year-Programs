// A class called Employee, which models an employee with an ID, name and salary, is designed as shown in the following class diagram.
// The method raiseSalary(percent) increases the salary by the given percentage.
// Develop the Employee class and suitable main method for demonstration.

public class Employee{
    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary){
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public int getId(){
        return id;
    }

    public String getName(){
        return name;
    }

    public double getSalary(){
        return salary;
    } 

    private void raiseSalary(double percent){
        if (percent > 0){
            double increasedAmount = (percent/100) * salary;
            salary += increasedAmount;
            System.out.println("Salary increased by " + percent + "% to " + salary);
        }
        else{
            System.out.println("Salary Increment Percentage should be greater than 0");
        }
    }

    public static void main(String[] args){
        Employee emp1 = new Employee(101, "John Doe", 100);

        System.out.println("ID: " + emp1.getId());
        System.out.println("Name: " + emp1.getName());
        System.out.println("Salary: " + emp1.getSalary());

        emp1.raiseSalary(10);

        System.out.println("ID: " + emp1.getId());
        System.out.println("Name: " + emp1.getName());
        System.out.println("Salary: " + emp1.getSalary());
    }
}