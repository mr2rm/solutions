# O(qlogq)

class MinHeap:
    def __init__(self):
        self.tree = []
        self.index = {}

    @property
    def top(self):
        if self.tree:
            return self.tree[0]

    def add(self, v):
        self.tree.append(v)
        i = len(self.tree) - 1
        while i > 0:
            p = (i - 1) // 2
            if self.tree[p] < self.tree[i]:
                break
            self.tree[p], self.tree[i] = self.tree[i], self.tree[p]
            i = p
        self.index[v] = i

    def delete(self, v):
        last = self.tree.pop()
        if last == v:
            return
        i = self.index[v]  # self.tree.index(v)
        self.tree[i] = last
        n = len(self.tree)
        while 2 * i + 1 < n:
            j = 2 * i + 1
            if j + 1 < n and self.tree[j + 1] < self.tree[j]:
                j += 1
            if self.tree[i] < self.tree[j]:
                break
            self.tree[i], self.tree[j] = self.tree[j], self.tree[i]
            i = j


heap = MinHeap()
q = int(input())
for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        heap.add(op[1])
    elif op[0] == 2:
        heap.delete(op[1])
    else:
        print(heap.top)
