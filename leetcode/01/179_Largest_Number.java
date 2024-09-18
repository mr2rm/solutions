import java.util.Arrays;

class Solution {
    public String largestNumber(int[] nums) {
        // Greedy, Sorting, String - Time: O(nlogn), Space: O(n + S)
        int n = nums.length;

        String[] strNums = new String[n];
        for (int i = 0; i < n; i++) {
            strNums[i] = Integer.toString(nums[i]);
        }

        Arrays.sort(strNums, (a, b) -> (b + a).compareTo(a + b));
        if (strNums[0].equals("0")) {
            return "0";
        }

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            res.append(strNums[i]);
        }
        return res.toString();
    }
}
