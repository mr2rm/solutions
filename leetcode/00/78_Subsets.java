import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> powerset;

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

    void optimizedFindPowerset(int i, List<Integer> subset, int[] nums) {
        if (i == nums.length) {
            powerset.add(new ArrayList<>(subset));
            return;
        }

        subset.add(nums[i]);
        optimizedFindPowerset(i + 1, subset, nums);
        subset.remove(subset.size() - 1);
        optimizedFindPowerset(i + 1, subset, nums);
    }

    public List<List<Integer>> subsets(int[] nums) {
        // Backtracking - Time: O(2^n), Space: O(2^n)
        // return findPowerset(0, new ArrayList<>(), nums);

        powerset = new ArrayList<>();
        optimizedFindPowerset(0, new ArrayList<>(), nums);
        return powerset;
    }
}
