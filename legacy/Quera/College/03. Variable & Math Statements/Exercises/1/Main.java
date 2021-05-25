import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt(), c = scanner.nextInt();
        int d = scanner.nextInt(), e = scanner.nextInt(), f = scanner.nextInt();
        System.out.printf("%d %d %d %d %d %d\n", 1 - a, 1 - b, 2 - c, 2 - d, 2 - e, 8 - f);
    }
}
