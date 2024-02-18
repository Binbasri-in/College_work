// Write a Java program to implement the Stack using arrays. Write Push(), Pop(), and Display()
// methods to demonstrate its working.

import java.util.*;

class Stack {
    int top = -1;
    int[] stack = new int[10];

    void push(int n) {
        if (top == 9) {
            System.out.println("Stack Overflow");
        } else {
            stack[++top] = n;
        }
    }

    void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
        } else {
            System.out.println("Popped element: " + stack[top--]);
        }
    }

    void display() {
        if (top == -1) {
            System.out.println("Stack Underflow");
        } else {
            System.out.println("The elements of the stack are: ");
            for (int i = top; i >= 0; i--) {
                System.out.println(stack[i]);
            }
        }
    }

    public static void main(String[] args) {
        int ch, n;
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        do {
            System.out.println("Enter your choice: ");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter the element to be pushed: ");
                    n = sc.nextInt();
                    s.push(n);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (ch != 4);
    }
}