// Develop a JAVA program to create an interface Resizable with methods resizeWidth(int width) and resizeHeight(int height) that allow an object to be resized.
// Create a class Rectangle that implement the Resizable interface and implements the resize methods

interface Resizable{
    void resizeWidth(int width);
    void resizeHeight(int height);
}

class Rectangle implements Resizable {
    private int width;
    private int height;

    public Rectangle(int width, int height){
        this.width = width;
        this.height = height;
    }

    @Override
    public void resizeWidth(int width){
        this.width = width;
        System.out.println("Width resized to " + width);
    }

    @Override
    public void resizeHeight(int height){
        this.height = height;
        System.out.println("Width resized to " + height);
    }

    public void displayDimensions(){
        System.out.println("Width: " + width + ", Height: " + height);
    }
}

public class TestResizable{
    public static void main(String[] args){
        Rectangle rectangle = new Rectangle(10, 5);

        System.out.println("Initial Dimensions");
        rectangle.displayDimensions();

        rectangle.resizeWidth(15);
        rectangle.resizeHeight(8);

        System.out.println("\nDimensions after resizing");
        rectangle.displayDimensions();
    }
}