# O(n)

class Queue:
    def __init__(self) -> None:
        self.enq_stack = []
        self.deq_stack = []

    def _fill_deq_stack(self):
        while self.enq_stack:
            self.deq_stack.append(self.enq_stack.pop())

    @property
    def front(self):
        if not self.deq_stack:
            self._fill_deq_stack()
        return self.deq_stack[-1]

    def enqueue(self, x):
        self.enq_stack.append(x)

    def dequeue(self):
        if not self.deq_stack:
            self._fill_deq_stack()
        return self.deq_stack.pop()


q = int(input())
queue = Queue()
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        queue.enqueue(query[1])
    elif query[0] == 2:
        queue.dequeue()
    else:
        print(queue.front)
