import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), res = 0;
        String s1 = scanner.next(), s2 = scanner.next();
        for (int i = 0; i < n; ++i)
            if (s1.charAt(i) != s2.charAt(i))
                res++;
        System.out.println(res);
    }
}
