import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int tmp = x;

        int[] cnt = new int[10];
        while (tmp != 0) {
            cnt[tmp % 10]++;
            tmp /= 10;
        }

        int res = 0;
        for (int n = x + 1; n <= 1_000_000; ++n) {
            tmp = n;
            int[] current_cnt = new int[10];
            while (tmp != 0) {
                current_cnt[tmp % 10]++;
                tmp /= 10;
            }

            boolean match = true;
            for (int i = 0; i < 10; ++i)
                if (current_cnt[i] != cnt[i]) {
                    match = false;
                    break;
                }

            if (match) {
                res = n;
                break;
            }
        }
        System.out.println(res);
    }
}