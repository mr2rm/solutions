from typing import List, Tuple


class Solution:
    dirs = [
        (0, 1),     # Right (+j)
        (1, 0),     # Down  (+i)
        (0, -1),    # Left  (-j)
        (-1, 0),    # Up    (-i)
    ]
    bound_dir = (1, -1, -1, 1)   # (Up, Right, Down, Left)

    def move(self, i: int, j: int, k: int) -> Tuple[int, int]:
        return i + self.dirs[k][0], j + self.dirs[k][1]

    def traverse(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        res = [*matrix.pop(0)]
        new_matrix = list(zip(*matrix))[::-1]
        res += self.traverse(new_matrix)
        return res

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # Simulation - Time: O(n^2), Space: O(?)
        # return self.traverse(matrix)

        n, m = len(matrix), len(matrix[0])
        res = []

        # Simulation - Time: O(n^2), Space: O(1)
        bound = [0, m - 1, n - 1, 0]
        i, j, k = 0, 0, 0
        while bound[0] <= bound[2] and bound[3] <= bound[1]:
            res.append(matrix[i][j])
            ti, tj = self.move(i, j, k)
            if bound[0] <= ti <= bound[2] and bound[3] <= tj <= bound[1]:
                i, j = ti, tj
            else:
                bound[k] += self.bound_dir[k]
                k = (k + 1) % 4
                i, j = self.move(i, j, k)

        # Simulation - Time: O(n^2), Space: O(1)
        # left, right = 0, m - 1
        # top, down = 0, n - 1
        # while left <= right and top <= down:
        #     # Right
        #     for j in range(left, right + 1):
        #         res.append(matrix[top][j])
        #     top += 1
        #     # Down
        #     for i in range(top, down + 1):
        #         res.append(matrix[i][right])
        #     right -= 1
        #     # Left
        #     if top > down:
        #         break
        #     for j in reversed(range(left, right + 1)):
        #         res.append(matrix[down][j])
        #     down -= 1
        #     # Up
        #     if left > right:
        #         break
        #     for i in reversed(range(top, down + 1)):
        #         res.append(matrix[i][left])
        #     left += 1

        # return res
