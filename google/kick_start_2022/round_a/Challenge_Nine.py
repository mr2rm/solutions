T = int(input())
for t in range(T):
    N = input()
    dig = (9 - sum(map(int, N)) % 9) % 9
    for i, d in enumerate(N):
        if int(d) > dig and (i != 0 or dig != 0):
            res = N[:i] + str(dig) + N[i:]
            break
    else:
        res = N + str(dig)
    print(f'Case #{t + 1}: {res}')
