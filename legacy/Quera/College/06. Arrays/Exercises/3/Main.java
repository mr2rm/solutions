import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int ASCII_RANGE = 256;
        int n = scanner.nextInt();

        String t = scanner.next();
        boolean[] discountSubAlpha = new boolean[ASCII_RANGE];
        for (int i = 0; i < t.length(); ++i)
            discountSubAlpha[t.charAt(i)] = true;

        for (int i = 0; i < n; ++i) {
            String s = scanner.next();
            boolean[] subAlpha = new boolean[ASCII_RANGE];
            for (int j = 0; j < s.length(); ++j)
                subAlpha[s.charAt(j)] = true;

            boolean is_valid = true;
            for (int j = 0; j < ASCII_RANGE; ++j)
                if (subAlpha[j] != discountSubAlpha[j]) {
                    is_valid = false;
                    break;
                }
            if (is_valid)   System.out.println("Yes");
            else            System.out.println("No");
        }
    }
}
