from collections import deque
from typing import List


class Solution:
    def __init__(self):
        self.mark = None
        self.adjlist = None
        self.inbound = None
        self.order = None

    def topolsort(self, u):
        self.mark[u] = True
        for v in self.adjlist[u]:
            if not self.mark[v]:
                self.topolsort(v)
        self.order.append(u)

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Toplogical Sort - Time: O(V + E), Space: O(V + E)
        # self.adjlist = [[] for _ in range(numCourses)]
        # self.inbound = [[] for _ in range(numCourses)]
        # for v, u in prerequisites:
        #     self.adjlist[u].append(v)
        #     self.inbound[v].append(u)

        # self.order = []
        # self.mark = [False] * numCourses
        # for u in range(numCourses):
        #     if not self.mark[u]:
        #         self.topolsort(u)

        # self.mark = [False] * numCourses
        # for v in reversed(self.order):
        #     for u in self.inbound[v]:
        #         if not self.mark[u]:
        #             return False
        #     self.mark[v] = True
        # return True

        # Topological Sort - Time: O(V + E), Space: O(V + E)
        indeg = [0] * numCourses
        adjlist = [[] for _ in range(numCourses)]
        for v, u in prerequisites:
            indeg[v] += 1
            adjlist[u].append(v)

        q = deque()
        for u in range(numCourses):
            if indeg[u] == 0:
                q.append(u)

        while q:
            u = q.popleft()
            for v in adjlist[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)
        return not any(indeg)
