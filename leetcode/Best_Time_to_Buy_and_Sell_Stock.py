from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Greedy - Time: O(n), Space: O(1)
        min_price, max_profit = prices[0], 0
        for p in prices:
            max_profit = max(max_profit, p - min_price)
            min_price = min(min_price, p)
        return max_profit
