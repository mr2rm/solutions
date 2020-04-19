t = int(input())

for tc in range(1, t + 1):
    n = int(input())
    arr = list(map(int, input().split()))

    res = 0
    for i in range(1, n - 1):
        if arr[i - 1] < arr[i] > arr[i + 1]:
            res += 1

    print('Case #%d: %d' % (tc, res))
