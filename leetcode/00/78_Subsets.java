import java.util.ArrayList;
import java.util.List;

class Solution {
    List<List<Integer>> findPowerset(int i, List<Integer> subset, int[] nums) {
        List<List<Integer>> powerset = new ArrayList<>();
        if (i == nums.length) {
            powerset.add(subset);
            return powerset;
        }

        List<List<Integer>> without_powerset = findPowerset(i + 1, subset, nums);
        powerset.addAll(without_powerset);

        List<Integer> newSubset = new ArrayList<Integer>(subset);
        newSubset.add(nums[i]);
        List<List<Integer>> with_powerset = findPowerset(i + 1, newSubset, nums);
        powerset.addAll(with_powerset);

        return powerset;
    }

    public List<List<Integer>> subsets(int[] nums) {
        // Backtracking - Time: O(2^n), Space: O(2^n)
        List<Integer> subset = new ArrayList<>();
        return findPowerset(0, subset, nums);
    }
}
