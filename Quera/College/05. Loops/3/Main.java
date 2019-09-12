import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        
        // while (n >= 10) {
        //     int sum = 0;
        //     while (n != 0) {
        //         sum += n % 10;
        //         n /= 10;
        //     }
        //     n = sum;
        // }
        
        n %= 9;
        if (n == 0)
            n = 9;
        
        System.out.println(n);
    }
}
