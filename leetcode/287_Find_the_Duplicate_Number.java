import java.util.HashMap;

class Solution {
    int solve1(int[] nums) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int x : nums) {
            if (map.containsKey(x)) {
                return x;
            }
            map.put(x, true);
        }
        return -1;
    }

    public int findDuplicate(int[] nums) {
        return this.solve1(nums);
    }
}
