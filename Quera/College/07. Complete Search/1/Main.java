import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt();
        String[] table = new String[n];
        for (int i = 0; i < n; ++i)
            table[i] = scanner.next();
        String s = scanner.next();
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= m - s.length(); ++j) {
                boolean match = true;
                for (int k = 0; k < s.length(); ++k)
                    if (s.charAt(k) != table[i].charAt(j + k)) {
                        match = false;
                        break;
                    }
                if (match) res++;
            }
        for (int i = 0; i <= n - s.length(); ++i)
            for (int j = 0; j < m; ++j) {
                boolean match = true;
                for (int k = 0; k < s.length(); ++k)
                    if (s.charAt(k) != table[i+k].charAt(j)) {
                        match = false;
                        break;
                    }
                if (match) res++;
            }
        System.out.println(res);
    }
}