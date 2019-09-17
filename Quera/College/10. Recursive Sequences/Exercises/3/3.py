def f(seq):
    if seq[-3:] == '000':
        return 0
    if len(seq) == n:
        return 1
    return f(seq + '0') + f(seq + '1')


n = int(input())
res = f('')
print(res)
