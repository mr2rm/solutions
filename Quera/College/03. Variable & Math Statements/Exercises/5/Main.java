import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = n / 2;
        long x = (long)m * (m + 1);
        int y = (1 - n % 2) * m;
        System.out.println((double)(x - y) / (n + 1));
    }
}
