T = int(input())
for t in range(T):
    I, P = input(), input()
    res = i = p = 0
    while i < len(I) and p < len(P):
        if I[i] == P[p]:
            i += 1
        else:
            res += 1
        p += 1

    if i < len(I):
        res = 'IMPOSSIBLE'
    else:
        res += len(P) - p
    print(f'Case #{t + 1}: {res}')
