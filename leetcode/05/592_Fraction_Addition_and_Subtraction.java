class Solution {
    int findGCD(int x, int y) {
        if (y == 0) {
            return x;
        }
        return findGCD(y, x % y);
    }

    public String fractionAddition(String expression) {
        // Math, String, Simulation - Time: O(n), Space: O(log(min(a, b)))
        String[] fractions = expression.split("/|(?=[-+])");

        int numerator = 0, denominator = 1;
        for (int i = 0; i < fractions.length; i += 2) {
            int a = Integer.parseInt(fractions[i]);
            int b = Integer.parseInt(fractions[i + 1]);
            numerator = (numerator * b) + (denominator * a);
            denominator *= b;
        }

        int gcd = Math.abs(findGCD(denominator, numerator));
        numerator /= gcd;
        denominator /= gcd;
        return numerator + "/" + denominator;
    }
}
