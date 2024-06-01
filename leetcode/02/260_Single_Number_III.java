import java.util.HashSet;

class Solution {
    int[] solve1(int[] nums) {
        // Hash Table - Time: O(n), Space: O(n)
        HashSet<Integer> set = new HashSet<>();
        for (int x : nums) {
            if (set.contains(x)) {
                set.remove(x);
            } else {
                set.add(x);
            }
        }

        int[] res = new int[2];
        int i = 0;
        for (int x : set) {
            res[i++] = x;
        }
        return res;
    }

    int[] solve2(int[] nums) {
        // Bit Manipulation - Time: O(n), Space: O(1)
        int xor = 0;
        for (int x : nums) {
            xor ^= x;
        }

        int lowestBit = xor & -xor;
        int a = 0, b = 0;
        for (int x : nums) {
            if ((x & lowestBit) == 0) {
                a ^= x;
            } else {
                b ^= x;
            }
        }

        return new int[] { a, b };
    }

    public int[] singleNumber(int[] nums) {
        return solve2(nums);
    }
}
