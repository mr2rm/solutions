import java.util.ArrayList;
import java.util.Arrays;
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

    int[] solve3(int[] nums1, int[] nums2) {
        // Sorting, Two Pointers - Time: O(nlogn), Space: O(n)
        int n = nums1.length;
        int m = nums2.length;
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        ArrayList<Integer> res = new ArrayList<>();
        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < m) {
            while (p2 < m && nums2[p2] < nums1[p1]) {
                p2++;
            }
            if (p2 < m && nums2[p2] == nums1[p1]) {
                res.add(nums1[p1]);
                p2++;
            }
            p1++;
        }

        return res.stream().mapToInt(i -> i).toArray();
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        return solve3(nums1, nums2);
    }
}
