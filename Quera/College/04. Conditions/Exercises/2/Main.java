import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt();
        int x = scanner.nextInt(), y = scanner.nextInt();
        if (x > a)
            System.out.println("Right");
        else
            System.out.println("Left");
    }
}
