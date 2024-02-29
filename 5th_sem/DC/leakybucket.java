import java.util.*;

public class leakybucket {
    private static int bucketSize = 0;
    private static int outputRate = 0;
    private static int inputRate = 0;
    private static int remainder = 0;

    public static void main(String[] args) {
        int totalLoops = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the No of Iterations: ");
        totalLoops = sc.nextInt();
        System.out.println("Enter the Bucket Size: ");
        bucketSize = sc.nextInt();
        System.out.println("Enter the Output Rate: ");
        outputRate = sc.nextInt();
        for (int i = 0; i < totalLoops; i++) {
            System.out.println("\nEnter the Input Rate: ");
            inputRate = sc.nextInt();
            inputRate = inputRate + remainder;
            if (inputRate > bucketSize) {
                System.out.println("Data Overflown by: " + (inputRate - bucketSize));
                inputRate = bucketSize;
            }
            remainder = inputRate - outputRate;
            if (remainder < 0) {
                System.out.println("Sorry you entered a wrong value ");
                System.exit(1);
            }
            System.out.println("\nInput rate: " + inputRate + "\nRemainder: " + remainder);
        }
        
        if (remainder != 0) {
            System.out.println("The buffer has " + remainder + " data left");
            remainder = 0;
        }
        sc.close();
    }
}