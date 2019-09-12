import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), l = scanner.nextInt();
        int curr = 0, prev = 0;
        for (int i = 0; i < n; ++i) {
            int d = scanner.nextInt(), r = scanner.nextInt(), g = scanner.nextInt();
            curr += d - prev;
            int currTimer = curr % (r + g);
            if (currTimer < r)
                curr += r - currTimer;
            prev = d;
        }
        curr += l - prev;
        System.out.println(curr);
    }
}
