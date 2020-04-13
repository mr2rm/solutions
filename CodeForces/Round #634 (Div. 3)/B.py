t = int(input())

for _ in range(t):
    n, a, b = map(int, input().split())

    s = ''.join(chr(ord('a') + i) for i in range(b))
    s += s[-1] * (a - len(s))
    for i in range(n - a):
        s += s[i]

    print(s)
