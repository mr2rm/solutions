import java.util.PriorityQueue;

record Fraction(int numerator, int denominator) implements Comparable<Fraction> {
    @Override
    public int compareTo(Fraction other) {
        int a = numerator * other.denominator;
        int b = denominator * other.numerator;
        if (a < b) {
            return -1;
        } else if (a > b) {
            return 1;
        } else {
            return 0;
        }
    }
}

class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        // Priority Queue - Time: O(n^2 * log(n^2)), Space: O(n^2)
        PriorityQueue<Fraction> pq = new PriorityQueue<>();
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                Fraction fraction = new Fraction(arr[i], arr[j]);
                pq.add(fraction);
            }
        }

        Fraction res = null;
        while (k > 0) {
            res = pq.poll();
            k--;
        }
        return new int[] { res.numerator(), res.denominator() };
    }
}
