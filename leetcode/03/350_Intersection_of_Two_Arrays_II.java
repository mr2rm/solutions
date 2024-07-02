import java.util.ArrayList;
import java.util.HashMap;
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

    int[] solve2(int[] nums1, int[] nums2) {
        // Hash Table - Time: O(n), Space: O(n)
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int x : nums2) {
            int count = map.getOrDefault(x, 0);
            map.put(x, count + 1);
        }

        List<Integer> res = new ArrayList<>();
        for (int x : nums1) {
            int count = map.getOrDefault(x, 0);
            if (count > 0) {
                res.add(x);
                map.put(x, count - 1);
            }
        }

        return res.stream().mapToInt(i -> i).toArray();
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        return solve2(nums1, nums2);
    }
}
