from collections import defaultdict


class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # Hash Table & Greedy - Time: O(n), Space: O(1)
        char_counter = defaultdict(int)
        for c in s:
            char_counter[c] += 1

        single_chars, double_chars = 0, 0
        for c, cnt in char_counter.items():
            q, r = divmod(cnt, 2)
            single_chars += r
            double_chars += q

        if single_chars > k:
            return False
        if k - single_chars > 2 * double_chars:
            return False
        return True
