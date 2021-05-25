def f():
    n = input()
    if n == '0':
        return
    f()
    print(n)


f()
