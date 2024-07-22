import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    void swap(String[] names, int[] heights, int i, int j) {
        String tempName = names[i];
        names[i] = names[j];
        names[j] = tempName;

        int tempHeight = heights[i];
        heights[i] = heights[j];
        heights[j] = tempHeight;
    }

    String[] solve1(String[] names, int[] heights) {
        // Array, Sorting - Time: O(n^2), Space: O(1)
        int n = names.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (heights[j] > heights[i]) {
                    swap(names, heights, i, j);
                }
            }
        }
        return names;
    }

    String[] solve2(String[] names, int[] heights) {
        // Hash Table, Sorting - Time: O(nlogn), Space: O(n)
        int n = names.length;

        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(heights[i], names[i]);
        }

        Arrays.sort(heights);
        for (int i = 0; i < n; i++) {
            names[i] = map.get(heights[n - i - 1]);
        }

        return names;
    }

    public String[] sortPeople(String[] names, int[] heights) {
        return solve2(names, heights);
    }
}
