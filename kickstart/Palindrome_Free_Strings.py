# Set 1 passed

def is_valid(s):
    for i in range(N):
        for j in range(i + 4, N):
            t = s[i:j + 1]
            if t == ''.join(reversed(t)):
                return False
    return True


def solve(s, i):
    if i == N:
        return is_valid(s)
    if s[i] != '?':
        return solve(s, i + 1)
    t = f'{s[:i]}{{}}{s[i + 1:]}'
    return solve(t.format(0), i + 1) or solve(t.format(1), i + 1)


T = int(input())
for t in range(T):
    N = int(input())
    S = input()
    res = 'POSSIBLE' if solve(S, 0) else 'IMPOSSIBLE'
    print(f'Case #{t + 1}: {res}')
