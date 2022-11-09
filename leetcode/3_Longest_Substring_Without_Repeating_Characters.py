class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0

        # Sliding Window - Time: O(n), Space: O(min(n, m))
        # chars = set()
        # # Approach 1
        # n, j = len(s), 0
        # for i, c in enumerate(s):
        #     while j < n and s[j] not in chars:
        #         chars.add(s[j])
        #         j += 1
        #     res = max(res, j - i)
        #     chars.remove(c)
        # # Approach 2
        # i = 0
        # for j, c in enumerate(s):
        #     while c in chars:
        #         chars.remove(s[i])
        #         i += 1
        #     chars.add(c)
        #     res = max(res, j - i + 1)

        # Optimized Sliding Window - Time: O(n), Space: O(min(n, m))
        index, i = {}, 0
        for j, c in enumerate(s):
            i = max(i, index.get(c, 0))
            res = max(res, j - i + 1)
            index[c] = j + 1

        return res
