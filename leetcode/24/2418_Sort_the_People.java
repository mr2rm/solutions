
class Solution {
    void swap(String[] names, int[] heights, int i, int j) {
        String tempName = names[i];
        names[i] = names[j];
        names[j] = tempName;

        int tempHeight = heights[i];
        heights[i] = heights[j];
        heights[j] = tempHeight;
    }

    public String[] sortPeople(String[] names, int[] heights) {
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
}
