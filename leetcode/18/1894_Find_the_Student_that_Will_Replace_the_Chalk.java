class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        // Simulation, Array - Time: O(n), Space: O(1)
        long sumOfChalk = 0;
        for (int c : chalk) {
            sumOfChalk += c;
        }
        long reminder = k % sumOfChalk;

        int res = -1;
        for (int i = 0; i < chalk.length; i++) {
            if (chalk[i] > reminder) {
                res = i;
                break;
            }
            reminder -= chalk[i];
        }
        return res;
    }
}
