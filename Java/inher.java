// A Design a superclass called Staff with details as StaffId, Name, Phone, Salary. Extend this class
// by writing three subclasses namely Teaching (domain, publications), Technical (skills), and
// Contract (period). Write a Java program to read and display at least 3 staff objects of all three
// categories.

import java.util.*;

class Staff {
    String staffId, name, phone;
    double salary;

    void getDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Staff ID: ");
        staffId = sc.nextLine();
        System.out.println("Enter the Name: ");
        name = sc.nextLine();
        System.out.println("Enter the Phone: ");
        phone = sc.nextLine();
        System.out.println("Enter the Salary: ");
        salary = sc.nextDouble();
    }

    void display() {
        System.out.println("Staff ID: " + staffId);
        System.out.println("Name: " + name);
        System.out.println("Phone: " + phone);
        System.out.println("Salary: " + salary);
    }
}

class Teaching extends Staff {
    String domain, publications;

    void getDetails() {
        super.getDetails();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Domain: ");
        domain = sc.nextLine();
        System.out.println("Enter the Publications: ");
        publications = sc.nextLine();
    }

    void display() {
        super.display();
        System.out.println("Domain: " + domain);
        System.out.println("Publications: " + publications);
    }
}

class Technical extends Staff {
    String skills;

    void getDetails() {
        super.getDetails();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Skills: ");
        skills = sc.nextLine();
    }

    void display() {
        super.display();
        System.out.println("Skills: " + skills);
    }
}

class Contract extends Staff {
    int period;

    void getDetails() {
        super.getDetails();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Period: ");
        period = sc.nextInt();
    }

    void display() {
        super.display();
        System.out.println("Period: " + period);
    }
}

class inher {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of staff: ");
        n = sc.nextInt();
        Staff[] s = new Staff[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the details of staff " + (i + 1));
            System.out.println("Enter the category of staff: ");
            System.out.println("1. Teaching");
            System.out.println("2. Technical");
            System.out.println("3. Contract");
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    s[i] = new Teaching();
                    break;
                case 2:
                    s[i] = new Technical();
                    break;
                case 3:
                    s[i] = new Contract();
                    break;
                default:
                    System.out.println("Invalid choice!");
                    i--;
                    continue;
            }
            s[i].getDetails();
        }
        System.out.println("The details of staff are: ");
        for (int i = 0; i < n; i++) {
            System.out.println("The details of staff " + (i + 1));
            s[i].display();
        }
    }
}
