def f(seq):
    global n
    if seq[-3:] == '000':
        return 0
    if len(seq) == n:
        return 1
    return f(seq + '0') + f(seq + '1')


def solve(x):
    if x <= 2:
        return 2 ** x
    return solve(x - 1) + solve(x - 2) + solve(x - 3)


n = int(input())

# res = f('')
res = solve(n)

print(res)
