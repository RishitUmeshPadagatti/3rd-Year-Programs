// Develop a JAVA program to create a class named shape
// Create three sub classes namely: Circle, Triangle and Square, each child has two member functions named draw() and erase()
// Demonstrate polymorphism concepts by developing suitable methods, defining members data and main program

class Shape{
    public void draw(){
        System.out.println("Drawing a Shape");
    }
    public void erase(){
        System.out.println("Erasing a Circle");
    }
}

class Circle extends Shape{
    public void draw(){
        System.out.println("Drawing a Circle");
    }
    public void erase(){
        System.out.println("Erasing a Circle");
    }
}

class Triangle extends Shape{
    public void draw(){
        System.out.println("Drawing a Triangle");
    }
    public void erase(){
        System.out.println("Erasing a Triangle");
    }
}

class Square extends Shape{
    public void draw(){
        System.out.println("Drawing a Square");
    }
    public void erase(){
        System.out.println("Erasing a Square");
    }
}

public class TestShapes{
    public static void main(String[] args){
        Shape[] shapes = new Shape[3];
        shapes[0] = new Circle();
        shapes[1] = new Triangle();
        shapes[2] = new Square();

        for (Shape shape: shapes){
            shape.draw();
            shape.erase();
            System.out.println();
        }
    }
}