// A class called MyPoint which models a 2D point with X and Y coordinates, is designed as follows:
// • Two instance variable X(int) and Y(int)
// • A default (or "no-arg") constructor that construct a point at the default location of (0, 0)
// • A overloaded constructor that construct a point with the given X and Y coordinates.
// • A method setXY to set both X and Y.
// • A method getXY which returns the X and Y in a 2-element int array.
// • A toString() method that returns a string description of the instance in that format" (X,Y)".
// • A method called distance (int X, Int Y) that returns the distance from this point to another point at the given (X, Y) coordinates.
// • An overloaded distance(MyPoint another) that returns the distance from this point to the given MyPoint instance (called another)
// • Another overloaded distance) method that returns the diatance from this point to the origin (0,0)
// Develop the code for the class MyPoint. Also develop a JAVA program (called TestMyPoint) to test all the methods defined in the class.

class MyPoint{
    private int x;
    private int y;

    public MyPoint(){
        this.x = 0;
        this.y = 0;
    }

    public MyPoint(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void setXY(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int[] getXY(){
        return new int[]{x, y};
    }

    public String toString(){
        return "(" + x + ", " + y + ")";
    }

    public double distance(int x, int y){
        int xDiff = this.x - x;
        int yDiff = this.y - y;
        return Math.sqrt(xDiff*xDiff + yDiff*yDiff);
    }

    public double distance(MyPoint another){
        int xDiff = this.x - another.x;
        int yDiff = this.y - another.y;
        return Math.sqrt(xDiff*xDiff + yDiff*yDiff);
    }

    public double distance(){
        return Math.sqrt(x*x + y*y);
    }
}

public class TestMyPoint{
    public static void main(String[] args){
        MyPoint point1 = new MyPoint();
        MyPoint point2 = new MyPoint(3, 4);

        System.out.println("Point 1: " + point1.toString());
        System.out.println("Point 2: " + point2.toString());

        point1.setXY(2, 2);
        
        System.out.println("Point 1 (after setXY): " + point1.toString());
        int[] coordinates = point1.getXY();

        System.out.println("Coordinates of Point 1: (" + coordinates[0] + ", " + coordinates[1] + ")");

        double distance1 = point1.distance(point2);
        System.out.println("Distance between Point1 and Point2: " + distance1);

        double distance2 = point1.distance();
        System.out.println("Distance between Point1 and Origin: " + distance2);
    }
}