class Solution {
    public boolean rotateString(String s, String goal) {
        // String - Time: O(n^2), Space: O(1)
        int n = s.length();
        if (goal.length() != n) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            boolean found = true;
            for (int j = 0; j < n; j++) {
                int k = (i + j) % n;
                if (s.charAt(k) != goal.charAt(j)) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return true;
            }
        }
        return false;
    }
}
