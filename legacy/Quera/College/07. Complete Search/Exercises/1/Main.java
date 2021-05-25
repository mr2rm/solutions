import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), x = scanner.nextInt(), y = scanner.nextInt();
        
        boolean found = false;
        for (int a = 0; a <= n / x; ++a)
            if ((n - a * x) % y == 0) {
                System.out.printf("%d %d\n", a, (n - a * x) / y);
                found = true;
                break;
            }
        
        if (!found)
            System.out.println(-1);
    }
}