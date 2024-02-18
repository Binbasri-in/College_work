// A Write a Java program to read two integers a and b. Compute a/b and print, when b is not zero.
// Raise an exception when b is equal to zero.

import java.util.*;

class Zero {
    public static void main(String[] args) {
        int a, b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of a: ");
        a = sc.nextInt();
        System.out.println("Enter the value of b: ");
        b = sc.nextInt();
        try {
            if (b == 0) {
                throw new ArithmeticException("Divide by zero error");
            }
            System.out.println("a/b = " + (a / b));
        } catch (ArithmeticException e) {
            System.out.println(e);
        }
    }
}