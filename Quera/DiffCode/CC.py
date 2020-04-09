def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def parse(s):
    a = b = 0
    arr = s.split('x')
    if arr[-1]:
        b += eval(arr[-1])

    for t in arr[:-1]:
        if not t or t[0].isdigit():
            t = f'+{t}'
        if not t[-1].isdigit():
            t = f'{t}1'

        for i in reversed(range(len(t))):
            if not t[i].isdigit():
                break

        a += int(t[i:])
        b += eval(t[:i] or '0')

    return a, b


n = int(input())
s, t = input().split('=')

a, b = parse(s)
c, d = parse(t)
q, p = a - c, d - b

if q:
    r = gcd(p, q)
    p, q = p // r, q // r
    print(p, q)
else:
    print('invalid')
