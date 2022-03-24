from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Time: O(nklogk), Space: O(nk)
        groups = defaultdict(list)
        for word in strs:
            # rep = ''.join(sorted(list(word)))
            rep = tuple(sorted(word))
            groups[rep].append(word)
        return list(groups.values())
