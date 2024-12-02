// Develop a JAVA program to add two matrices of suitable order N(The value of N should be read from command line arguments)

import java.util.Scanner;
public class MatrixAddition{
    public static void main(String[] args){
        if (args.length!=1){
            System.out.println("Matrix Addition order N");
            return;
        }

        int N = Integer.parseInt(args[0]);

        int[][] matrix1 = new int[N][N];
        int[][] matrix2 = new int[N][N];
        int[][] result = new int[N][N];

        System.out.println("\nEnter elements for Matrix 1");
        inputMatrix(matrix1);

        System.out.println("\nEnter elements for Matrix 2");
        inputMatrix(matrix2);

        addMatrix(matrix1, matrix2, result);

        System.out.println("\nResultant Matrix after addition");
        displayMatrix(result);
    }

    private static void inputMatrix(int[][] matrix){
        Scanner sc = new Scanner(System.in);
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                System.out.print("Enter position at (" + i + ", " + j + "): ");
                matrix[i][j] = sc.nextInt();
            }
        }
    }

    private static void addMatrix(int[][] matrix1, int[][] matrix2, int[][] result){
        for (int i=0; i<result.length; i++){
            for (int j=0; j<result[0].length; j++){
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }

    private static void displayMatrix(int[][] matrix){
        for (int i=0; i<matrix.length; i++){
            for (int j=0; j<matrix[0].length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}