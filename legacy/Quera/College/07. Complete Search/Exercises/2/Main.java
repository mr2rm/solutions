import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next(), p = scanner.next();

        boolean found = false;
        for (int i = 0; i < s.length() && !found; ++i) {
            boolean match = true;
            for (int j = i, k = 0; k < p.length(); j = (j + 1) % s.length(), ++k)
                if (p.charAt(k) != s.charAt(j)) {
                    match = false;
                    break;
                }
            if (match)  found = true;
        }
        System.out.println(found ? "Yes" : "No");
    }
}