import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        long res = 0;
        for (int a = 1; a <= n / 3; ++a) {
            int l = Math.max(n / 2 - 2 * a + 1, 0), r = (n - 3 * a) / 2;
            res += r - l + 1;
        }
        System.out.println(res);
    }
}