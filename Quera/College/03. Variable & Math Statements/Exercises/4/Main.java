import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(), b = scanner.nextInt();
        System.out.printf("%02d:%02d\n", (12 - a) % 12, (60 - b) % 60);
    }
}
