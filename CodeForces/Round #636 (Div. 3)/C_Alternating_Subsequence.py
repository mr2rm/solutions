def sign(x):
    return x > 0


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    res = i = 0
    while i < n:
        maxi = arr[i]
        for j in range(i, n + 1):
            if j == n or sign(arr[j]) != sign(arr[i]):
                break
            maxi = max(maxi, arr[j])

        res += maxi
        i = j

    print(res)
