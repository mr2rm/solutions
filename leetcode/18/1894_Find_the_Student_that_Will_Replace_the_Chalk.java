import java.util.Arrays;

class Solution {
    int solve1(int[] chalk, int k) {
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

    int solve2(int[] chalk, int k) {
        // Prefix Sum, Binary Search - Time: O(n), Space: O(n)
        int n = chalk.length;

        long[] prefixSum = new long[n];
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }

        long reminder = k % prefixSum[n - 1];
        int res = Arrays.binarySearch(prefixSum, reminder) + 1;
        if (res < 0) {
            res = Math.abs(res);
        }
        return res;
    }

    public int chalkReplacer(int[] chalk, int k) {
        return solve2(chalk, k);
    }
}
