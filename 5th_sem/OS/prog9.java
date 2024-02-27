// 9. Write a program to simulate paging technique of memory management
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
        int[] s = new int[10];
        int[][] fno = new int[10][20];

        System.out.print("\nEnter the memory size -- ");
        ms = scanner.nextInt();
        System.out.print("\nEnter the page size -- ");
        ps = scanner.nextInt();
        nop = ms / ps;
        System.out.println("\nThe no. of pages available in memory are -- " + nop);
        System.out.print("\nEnter number of processes -- ");
        np = scanner.nextInt();
        rempages = nop;

        for (i = 1; i <= np; i++) {
            System.out.print("\nEnter no. of pages required for p[" + i + "]-- ");
            s[i] = scanner.nextInt();
            if (s[i] > rempages) {
                System.out.println("\nMemory is Full");
                break;
            }
            rempages = rempages - s[i];
            System.out.print("\nEnter pagetable for p[" + i + "] --- ");
            for (j = 0; j < s[i]; j++)
                fno[i][j] = scanner.nextInt();
        }

        System.out.println("\nEnter Logical Address to find Physical Address ");
        System.out.println("\nEnter process no. and pagenumber and offset -- ");
        x = scanner.nextInt();
        y = scanner.nextInt();
        offset = scanner.nextInt();

        if (x > np || y >= s[x] || offset >= ps)
            System.out.println("\nInvalid Process or Page Number or offset");
        else {
            pa = fno[x][y] * ps + offset;
            System.out.println("\nThe Physical Address is -- " + pa);
        }

        scanner.close();
    }

Sample Input
Enter the memory size -- 1000
Enter the page size -- 100
The no. of pages available in memory are -- 10 
Enter number of processes -- 3
Enter no. of pages required for p[1]-- 4
Enter pagetable for p[1] --- 8 6 9 5
Enter no. of pages required for p[2]-- 5
Enter pagetable for p[2] --- 1 4 5 7 3
Enter no. of pages required for p[3]-- 5
Memory is Full
Enter Logical Address to find Physical Address 
Enter process no. and pagenumber and offset -- 2
3
60
The Physical Address is -- 760
