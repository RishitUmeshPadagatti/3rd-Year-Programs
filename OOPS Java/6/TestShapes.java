// Develop a JAVA program to create an abstract class Shape with abstract methods calculateArea() and calculatePerimeter().
// Create subclasses Circle and Traingle that extend the Shape class and implement the respective methods to calculate the area and perimeter of each shape.

abstract class Shape{
    public abstract double calculateArea();
    public abstract double calculatePerimeter();
}

class Circle extends Shape{
    private double radius;

    public Circle(double radius){
        this.radius = radius;
    }

    @Override
    public double calculateArea(){
        return Math.PI * radius * radius;
    }

    @Override
    public double calculatePerimeter(){
        return 2 * Math.PI * radius;
    }
}

class Triangle extends Shape{
    private double a;
    private double b;
    private double c;

    public Triangle(double a, double b, double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double calculateArea(){
        double s = (a + b + c)/2;
        return Math.sqrt(s * (s-a) * (s-b) * (s-c));
    }

    @Override
    public double calculatePerimeter(){
        return a + b + c;
    }
}

public class TestShapes{
    public static void main(String[] args){
        Circle circle = new Circle(5.0);
        Triangle triangle = new Triangle(3, 4, 5);

        System.out.println("Circle");
        System.out.println("Area: " + circle.calculateArea());
        System.out.println("Perimeter: " + circle.calculatePerimeter());

        System.out.println();

        System.out.println("Triangle");
        System.out.println("Area: " + triangle.calculateArea());
        System.out.println("Perimeter: " + triangle.calculatePerimeter());
        
    }
}