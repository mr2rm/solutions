import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int res = -1, cnt, idx;
        for (int i = 0; i < n; ++i) {
            String str = scanner.next();
            boolean[] mark = new boolean[26];
            cnt = 0;
            for (int j = 0; j < str.length(); ++j) {
                idx = str.charAt(j) - 'a';
                if (!mark[idx]) {
                    cnt++;
                    mark[idx] = true;
                }
            }
            res = Math.max(res, cnt);
        }
        System.out.println(res);
    }
}
