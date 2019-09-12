import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt(), res = 0;
        for (int i = 0; i < n; ++i) {
            String str = scanner.next();
            for (int j = 0; j < str.length(); ++j)
                if (str.charAt(j) == '*')
                    res += 1;
        }
        System.out.println(res);
    }
}
