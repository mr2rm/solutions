import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), m = scanner.nextInt();
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cost[i][j] = scanner.nextInt();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int x = scanner.nextInt(), y = scanner.nextInt();
            res += cost[x-1][y-1];
        }
        System.out.println(res);
    }
}
