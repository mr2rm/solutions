import java.util.Scanner;
import java.lang.StringBuilder;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt(), r = scanner.nextInt();
        StringBuilder str = new StringBuilder("1");
        for (int i = 0, size = 1; str.length() < r; ++i) {
            if (i == size) {
                size *= 2;
                i = 0;
            }
            str.append((char)('0' + '1' - str.charAt(i)));
        }
        System.out.println(str.substring(l - 1));
    }
}

