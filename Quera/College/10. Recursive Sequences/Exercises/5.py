n, avg = int(input()), 0


def f(i, s):
    global avg, n
    if i == n:
        avg = s // n
        return 0
    x = int(input())
    res = f(i + 1, s + x)
    if x > avg:
        res += x - avg
    return res


res = f(0, 0)
print(res)
