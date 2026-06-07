import java.util.*;

public class Solution {
    public static List<List<Integer>> twoSum(int[] nums, int i) {
        List<List<Integer>> triplets = new ArrayList<>();
        int l = i + 1;
        int r = nums.length - 1;
        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s < 0) {
                l++;
            } else if (s > 0) {
                r--;
            } else {
                triplets.add(Arrays.asList(nums[i], nums[l], nums[r]));
                l++;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
                r--;
                while (l < r && nums[r] == nums[r + 1]) {
                    r--;
                }
            }
        }
        return triplets;
    }

    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> triplets = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            triplets.addAll(twoSum(nums, i));
        }
        return triplets;
    }
}
