// Write a Java class called Customer to store their name and date_of_birth. The date_of_birth
// format should be dd/mm/yyyy. Write methods to read customer data as <name, dd/mm/yyyy>
// and display as <name, dd, mm, yyyy> using StringTokenizer class considering the delimiter
// character as “/”.

import java.util.*;

class Customer {
    String name, dob;

    void getDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name: ");
        name = sc.nextLine();
        System.out.println("Enter the date of birth: ");
        dob = sc.nextLine();
    }

    void display() {
        StringTokenizer st = new StringTokenizer(dob, "/");
        System.out.println("Name: " + name);
        System.out.println("Date of birth: ");
        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }
    }

    public static void main(String[] args) {
        Customer c = new Customer();
        c.getDetails();
        c.display();
    }
}