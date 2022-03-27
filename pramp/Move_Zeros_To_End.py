def moveZerosToEnd(arr):
    """
    @param arr: int[]
    @return: int[]
    """
    # Time: O(n), Space: O(1)
    w = 0
    for r, x in enumerate(arr):
        if x != 0:
            arr[r], arr[w] = arr[w], arr[r]
            w += 1
    return arr

    # Time: O(n), Space: O(1)
    # n, w = len(arr), 0
    # for r in range(n):
    #     if arr[r] != 0:
    #         arr[w] = arr[r]
    #         w += 1
    # for i in range(w, n):
    #     arr[i] = 0
    # return arr

    # Time: O(n), Space: O(1)
    # n, j = len(arr), 0
    # for i in range(n):
    #     if arr[i] != 0:
    #         continue
    #     j = max(j, i + 1)
    #     while j < n and arr[j] == 0:
    #         j += 1
    #     if j == n:
    #         break
    #     arr[i], arr[j] = arr[j], arr[i]
    #     j += 1
    # return arr

    # Time: O(n), Space: O(1)
    # n = len(arr)
    # i = j = 0
    # while i < n and j < n:
    #     while i < n and arr[i] != 0:
    #         i += 1
    #     j = max(j, i + 1)
    #     while j < n and arr[j] == 0:
    #         j += 1
    #     if i < n and j < n:
    #         arr[i], arr[j] = arr[j], arr[i]
    #         i += 1
    #         j += 1
    # return arr

    # Time: O(n), Space: O(n)
    # zcnt = 0
    # res = []
    # for x in arr:
    #     if x == 0:
    #         zcnt += 1
    #     else:
    #         res.append(x)
    # res.extend([0] * zcnt)
    # return res

    # Time: O(n^2), Space: O(1)
    # n = len(arr)
    # for i in range(n):
    #     if arr[i] == 0:
    #         for j in range(i + 1, n):
    #             if arr[j] != 0:
    #                 arr[i], arr[j] = arr[j], arr[i]
    #                 break
    # return arr

    # Time: O(n^2), Space: O(1)
    # n, i = len(arr), 0
    # while n:
    #     if arr[i] == 0:
    #         # arr.remove(0)
    #         # arr.append(0)
    #         arr = arr[:i] + arr[i + 1:] + [0]
    #     else:
    #         i += 1
    #     n -= 1
    # return arr


arr = list(map(int, input().split()))
print(' '.join(map(str, moveZerosToEnd(arr))))
