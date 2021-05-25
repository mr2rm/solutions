t = int(input())
for _ in range(t):
    n = int(input())

    if (n // 2) % 2 != 0:
        print('NO')
        continue

    print('YES')
    res = [None] * n
    for i in range(0, 3 * n // 2, 3):
        e, o = i + 1, i + 2
        if i % 2 == 0:
            e, o = o, e

        j = i // 3
        res[j], res[n - j - 1] = e, o

    res = ' '.join(map(str, res))
    print(res)
