// Write a Java class called Customer to store their name and date_of_birth. The date_of_birth
// format should be dd/mm/yyyy. Write methods to read customer data as <name, dd/mm/yyyy>
// and display as <name, dd, mm, yyyy> using StringTokenizer class considering the delimiter
// character as “/”.

import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        String name;
        System.out.println("Enter the name & DOB in the format <name,dd/mm/yyyy>");
        name = scan.next();
        
        StringTokenizer st = new StringTokenizer(name,"/");
        int count = st.countTokens();
        for (int i =1; i<=count && st.hasMoreTokens();i++)
        {
            System.out.print(st.nextToken());
            if(i<count)
            System.out.print(",");
        }
        scan.close();
    }
}
