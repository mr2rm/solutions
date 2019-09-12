import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] count = new int[111];
        for (int i = 0; i < n; ++i) {
            int color = scanner.nextInt();
            count[color]++;
        }
        int res = -1;
        for (int i = 1; i <= 100; ++i) {
            if (count[i] == 0)   continue;
            if (res == -1 || count[i] < count[res])
                res = i;
        }
        System.out.println(res);
    }
}
