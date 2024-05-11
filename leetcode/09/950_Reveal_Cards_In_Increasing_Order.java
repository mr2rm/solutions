import java.util.Arrays;

class Solution {
    int[] solve1(int[] deck) {
        // Two Pointers, Sorting, Simulation - Time: O(nlogn), Space: O(n)
        int n = deck.length;
        int[] res = new int[n];

        int resIdx = 0;
        int deckIdx = 0;
        boolean skip = false;

        Arrays.sort(deck);

        while (deckIdx < n) {
            if (res[resIdx] == 0) {
                if (!skip) {
                    res[resIdx] = deck[deckIdx];
                    deckIdx++;
                }
                skip = !skip;
            }
            resIdx = (resIdx + 1) % n;
        }

        return res;
    }

    public int[] deckRevealedIncreasing(int[] deck) {
        return solve1(deck);
    }
}
