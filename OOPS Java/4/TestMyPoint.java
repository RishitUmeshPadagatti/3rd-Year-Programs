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