import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(), y = scanner.nextInt();
        int res = -1;
        if (y == x || y == x - 2) {
            int a = x / 2;
            int b = x % 2;
            res = 4 * a + b;
            if (y != x)
                res -= 2;
        }
        System.out.println(res);
    }
}
