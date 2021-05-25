import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt();
        int c = scanner.nextInt(), d = scanner.nextInt();
        System.out.printf("Sum : %.6f\n", (double)a + b + c + d);
        System.out.printf("Average : %.6f\n", (a + b + c + d) / 4.);
        System.out.printf("Product : %.6f\n", (double)a * b * c * d);
        int x = (a + b + Math.abs(a - b)) / 2, y = (c + d + Math.abs(c - d)) / 2;
        System.out.printf("MAX : %.6f\n", (x + y + Math.abs(x - y)) / 2.);
        x = (a + b - Math.abs(a - b)) / 2;
        y = (c + d - Math.abs(c - d)) / 2;
        System.out.printf("MIN : %6f\n", (x + y - Math.abs(x - y)) / 2.);
    }
}
