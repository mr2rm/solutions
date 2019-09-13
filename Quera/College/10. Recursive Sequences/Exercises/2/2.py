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


def precompute_fib(n):
    global mem_fib
    mem_fib[0] = mem_fib[1] = 1
    for i in range(2, n + 1):
        mem_fib[i] = mem_fib[i - 1] + mem_fib[i - 2]


n, res = int(input()), ''

# needed for precompute_fib and memoized_fib
mem_fib = [-1] * 21
# precompute_fib(20)

# loop over numbers and check if in precomputed fibs
# index = 0
# for i in range(1, n + 1):
#     # res += '+' if i in mem_fib else '-'
#     while mem_fib[index] < i:
#         index += 1
#     res += '+' if mem_fib[index] == i else '-'

# attach precomputed fibs
# for i in range(1, 21):
#     x = mem_fib[i] - mem_fib[i - 1] - 1
#     res += ('-' * x) + '+'
# res = res[:n]

# loop over numbers and compare each to next fib
get_fib, latest_fib = next_fib(), -1
for i in range(1, n + 1):
    while latest_fib < i:
        latest_fib = next(get_fib)
    res += '+' if latest_fib == i else '-'

print(res)
