import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int ax = scanner.nextInt(), ay = scanner.nextInt();
        int bx = scanner.nextInt(), by = scanner.nextInt();
        int cx = scanner.nextInt(), cy = scanner.nextInt();
        int x, y;
        if (bx == cx)       x = ax;
        else if (ax == cx)  x = bx;
        else                x = cx;
        if (by == cy)       y = ay;
        else if (ay == cy)  y = by;
        else                y = cy;
        System.out.printf("%d %d\n", x, y);
    }
}
