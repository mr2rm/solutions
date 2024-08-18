import java.util.TreeSet;

class Solution {
    public int nthUglyNumber(int n) {
        // Set - Time: O(nlogm), Space: O(m)
        TreeSet<Long> uglySet = new TreeSet<>();
        uglySet.add(1L);

        Long currUgly = 1L;
        for (int i = 0; i < n; i++) {
            currUgly = uglySet.pollFirst();
            uglySet.add(currUgly * 2);
            uglySet.add(currUgly * 3);
            uglySet.add(currUgly * 5);
        }

        return currUgly.intValue();
    }
}
