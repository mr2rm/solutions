import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String health_label = scanner.next();
        int g = 0, r = 0, y = 0;
        
        if (health_label.charAt(0) == 'G')      g += 1;
        else if (health_label.charAt(0) == 'R') r += 1;
        else                                    y += 1;
        if (health_label.charAt(1) == 'G')      g += 1;
        else if (health_label.charAt(1) == 'R') r += 1;
        else                                    y += 1;
        if (health_label.charAt(2) == 'G')      g += 1;
        else if (health_label.charAt(2) == 'R') r += 1;
        else                                    y += 1;
        if (health_label.charAt(3) == 'G')      g += 1;
        else if (health_label.charAt(3) == 'R') r += 1;
        else                                    y += 1;
        if (health_label.charAt(4) == 'G')      g += 1;
        else if (health_label.charAt(4) == 'R') r += 1;
        else                                    y += 1;
        
        if (r >= 3 || (r >= 2 && y >= 2) || g == 0)
            System.out.println("nakhor lite");
        else
            System.out.println("rahat baash");
    }
}
