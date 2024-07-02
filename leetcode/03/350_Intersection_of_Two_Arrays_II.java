import java.util.ArrayList;
import java.util.List;

class Solution {
    int[] solve1(int[] nums1, int[] nums2) {
        // Array, Brute Force - Time: O(n^2), Space: O(n)
        int n = nums2.length;
        boolean[] mark = new boolean[n];
        List<Integer> res = new ArrayList<>();
        for (int x : nums1) {
            for (int i = 0; i < n; i++) {
                if (!mark[i] && nums2[i] == x) {
                    res.add(x);
                    mark[i] = true;
                    break;
                }
            }
        }
        return res.stream().mapToInt(i -> i).toArray();
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        return solve1(nums1, nums2);
    }
}
