from typing import List, Tuple, Optional, Set
from collections import defaultdict


class Solution:
    def dfs(self, u: str, target: str, factor: float) -> Optional[float]:
        if u == target:
            return factor

        self.visited.add(u)
        for v, w in self.graph[u]:
            if v not in self.visited:
                res = self.dfs(v, target, w * factor)
                if res is not None:
                    return res

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # DFS - Time: O(n^2), Space: O(n)
        self.graph: List[Tuple[str, int]] = defaultdict(list)
        self.visited: Set[str] = set()
        for (u, v), w in zip(equations, values):
            self.graph[u].append((v, w))
            self.graph[v].append((u, 1 / w))

        res: List[float] = []
        for u, v in queries:
            self.visited.clear()
            factor = None
            if u in self.graph and v in self.graph:
                factor = self.dfs(u, v, 1)
            res.append(-1.0 if factor is None else factor)

        return res
