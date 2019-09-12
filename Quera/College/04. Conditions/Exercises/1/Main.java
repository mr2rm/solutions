import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String x = scanner.next(), y = scanner.next(), tmp;
        if (x.charAt(2) != y.charAt(2)) {
            if (x.charAt(2) > y.charAt(2)) {
                tmp = x;
                x = y;
                y = tmp;
            }
        } else if (x.charAt(1) != y.charAt(1)) {
            if (x.charAt(1) > y.charAt(1)) {
                tmp = x;
                x = y;
                y = tmp;
            }
        } else if (x.charAt(0) != y.charAt(0)) {
            if (x.charAt(0) > y.charAt(0)) {
                tmp = x;
                x = y;
                y = tmp;
            }
        }
        if (x.equals(y))
            System.out.println(x + " = " + y);
        else
            System.out.println(x + " < " + y);
    }
}
