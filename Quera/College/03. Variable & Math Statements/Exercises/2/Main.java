import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = n / 2;
        int b = n - a;
        System.out.println((a + 1) * (b + 1));
    }
}
