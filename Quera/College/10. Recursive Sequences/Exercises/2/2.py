def fib(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    return fib(n - 1) + fib(n - 2)


def next_fib():
    i = 1
    while True:
        yield fib(i)
        i += 1


n, res = int(input()), ''
get_fib, latest_fib = next_fib(), -1
for i in range(1, n + 1):
    while latest_fib < i:
        latest_fib = next(get_fib)
    res += '+' if latest_fib == i else '-'
print(res)
