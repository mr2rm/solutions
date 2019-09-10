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


x = 5
result = fact(x)
print(f'fact({x}) = {result}')

x = 7
result = fib(x)
print(f'fib({x}) = {result}')

x = 4
result = f(x)
print(f'f({x}) = {result}')
