import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt(), x = scanner.nextInt();
        int res = 0;
        for (int n = 1; n <= a && n < x; ++n)
            if (a % n == 0)
                for (int m = 1; m <= b && n + m <= x; ++m)
                    if (b % m == 0)
                        res++;
        System.out.println(res);
    }
}
