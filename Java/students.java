/*
Create a Java class called Student with the following details as variables within it.
a. USN
b. Name
c. Branch
d. Phone
Write a Java program to create n Student objects and print the USN, Name, Branch, and Phone of
these objects with suitable headings.
*/

import java.util.*;

class Student {
    String usn, name, branch, phone;

    void getDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the USN: ");
        usn = sc.nextLine();
        System.out.println("Enter the Name: ");
        name = sc.nextLine();
        System.out.println("Enter the Branch: ");
        branch = sc.nextLine();
        System.out.println("Enter the Phone: ");
        phone = sc.nextLine();
    }

    void display() {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        System.out.println("Branch: " + branch);
        System.out.println("Phone: " + phone);
    }

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        n = sc.nextInt();
        Student[] s = new Student[n];
        for (int i = 0; i < n; i++) {
            s[i] = new Student();
            System.out.println("Enter the details of student " + (i + 1));
            s[i].getDetails();
        }
        System.out.println("The details of students are: ");
        for (int i = 0; i < n; i++) {
            System.out.println("The details of student " + (i + 1));
            s[i].display();
        }
    }
}
