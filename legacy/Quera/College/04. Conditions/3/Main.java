import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt();
        int x = scanner.nextInt(), y = scanner.nextInt();
        if (a == x)
            System.out.println("Vertical");
        else if (b == y)
            System.out.println("Horizontal");
        else
            System.out.println("Try again");
    }
}
