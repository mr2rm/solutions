from collections import defaultdict
from typing import Tuple, List
from functools import cmp_to_key
import heapq


class Solution:

    @staticmethod
    def cmp(a: Tuple[str, int], b: Tuple[str, int]):
        if a[1] != b[1]:
            return -1 if a[1] > b[1] else 1
        return -1 if a[0] < b[0] else 1

    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        word_count = defaultdict(int)
        for w in words:
            word_count[w] += 1

        # Sort - Time: O(nlogn), Space: O(n)

        # Simple sort
        # sorted_words = sorted([(-c, w) for w, c in word_count.items()])
        # return [w for _, w in sorted_words[:k]]

        # Sort using the comparison function
        # sorted_words = sorted(word_count.items(), key=cmp_to_key(self.cmp))
        # return [w for w, _ in sorted_words[:k]]

        # Heap - Time: O(klogn), Space: O(n)

        # Heap with nsmallest
        # items = [(-c, w) for w, c in word_count.items()]
        # k_items = heapq.nsmallest(k, items)
        # return [w for _, w in k_items]

        # Heap with nsmallest and comparison function
        items = list(word_count.items())
        k_items = heapq.nsmallest(k, items, key=cmp_to_key(self.cmp))
        return [w for w, _ in k_items]
