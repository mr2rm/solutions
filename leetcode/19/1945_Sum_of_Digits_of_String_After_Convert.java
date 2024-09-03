class Solution {
    String sumOfDigits(String s) {
        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += c - '0';
        }
        return String.valueOf(sum);
    }

    public int getLucky(String s, int k) {
        // Simulation, String - Time: O(n), Space: O(n)
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            int pos = c - 'a' + 1;
            sb.append(pos);
        }

        String res = sb.toString();
        for (int i = 0; i < k; i++) {
            res = sumOfDigits(res);
        }
        return Integer.parseInt(res);
    }
}
