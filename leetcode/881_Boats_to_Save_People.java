import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        // Greedy, Two Pointers - Time: O(nlogn), Space: O(1)
        int res = 0;
        Arrays.sort(people);

        int l = 0;
        int r = people.length - 1;
        while (l < r) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
            res++;
        }

        if (l == r) {
            res++;
        }
        return res;
    }
}
