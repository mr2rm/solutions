def fib(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    return fib(n - 1) + fib(n - 2)


def memoized_fib(n):
    global mem_fib
    if mem_fib[n] != -1:
        return mem_fib[n]
    if n == 1:
        mem_fib[n] = 1
    elif n == 2:
        mem_fib[n] = 2
    else:
        mem_fib[n] = memoized_fib(n - 1) + memoized_fib(n - 2)
    return mem_fib[n]


def next_fib():
    i = 1
    while True:
        # yield fib(i)
        yield memoized_fib(i)
        i += 1


# def precomputed_fib(n):
#     global fib_mem
#     fib_mem[0] = fib_mem[1] = 1
#     for i in range(2, 21):
#         fib_mem[i] = fib_mem[i - 1] + fib_mem[i - 2]


n, res = int(input()), ''

mem_fib = [-1] * 21
get_fib, latest_fib = next_fib(), -1

for i in range(1, n + 1):
    while latest_fib < i:
        latest_fib = next(get_fib)
    res += '+' if latest_fib == i else '-'

print(res)
