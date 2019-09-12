def fact(n):
    if n == 1:
        return 1
    return n * fact(n - 1)


def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 1) + fib(n - 2)


def f(n):
    if n == 0:
        return 1
    if n == 1:
        return 2
    return f(n - 1) + f(n - 2)


def gcd(a, b):
    if a > b:
        return gcd(b, a)
    if a == 0:
        return b
    return gcd(b % a, a)


def prt(a, b):
    if a == b:
        return
    prt(a + 1, b)
    print(a)


x = 5
result = fact(x)
print(f'fact({x}) = {result}')

x = 7
result = fib(x)
print(f'fib({x}) = {result}')

x = 4
result = f(x)
print(f'f({x}) = {result}')

x, y = 18, 12
result = gcd(x, y)
print(f'gcd({x}, {y}) = {result}')

x, y = 2, 5
print(f'prt({x}, {y}):')
result = prt(x, y)
