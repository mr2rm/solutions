from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)

        # Time: O(nklogk), Space: O(nk)
        # for word in strs:
        #     # rep = ''.join(sorted(list(word)))
        #     rep = tuple(sorted(word))
        #     groups[rep].append(word)

        # Time: O(nk), Space: O(nk)
        for word in strs:
            cnt = [0] * 26
            for c in word:
                cnt[ord(c) - ord('a')] += 1
            rep = tuple(cnt)
            groups[rep].append(word)

        return list(groups.values())
