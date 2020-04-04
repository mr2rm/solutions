t, b = map(int, input().split())
for tc in range(1, t + 1):
    res = ''
    for i in range(10):
        print(i + 1)
        res += input()

    print(res, flush=True)
    res = input()

    if res == 'N':
        break
