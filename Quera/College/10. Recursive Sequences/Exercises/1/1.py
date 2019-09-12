def f(n):
    if n == 0:
        return 5
    result = f(n - 1)
    if n % 2 == 0:
        return result - 21
    return result * result


x = int(input())
res = f(x)
print(res)
