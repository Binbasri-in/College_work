import java.net.*;
import java.util.*;

public class ipmac {
    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the host name");
            String hostname = sc.nextLine();
            InetAddress ipaddress = InetAddress.getByName(hostname);
            System.out.println("IP address : " + ipaddress);
            NetworkInterface ni = NetworkInterface.getByInetAddress(ipaddress);
            if (ni != null) {
                byte mac[] = ni.getHardwareAddress();
                if (mac != null) {
                    System.out.print("Mac address:");
                    for (int i = 0; i < mac.length; i++) {
                        System.out.format("%02X%s", mac[i], (i < mac.length - 1) ? ":" : " ");
                    }
                } else
                    System.out.println("Address not accessible");
            } else
                System.out.println("Network interface not found");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}