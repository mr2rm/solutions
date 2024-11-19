class Solution {
    public int[] decrypt(int[] code, int k) {
        // Simulation, Array - Time: O(n^2), Space: O(n)
        int n = code.length;
        int[] res = new int[n];

        int dir = k >= 0 ? 1 : -1;
        int count = Math.abs(k);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= count; j++) {
                int idx = (i + dir * j + n) % n;
                res[i] += code[idx];
            }
        }
        return res;
    }
}
