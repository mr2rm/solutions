n = int(input())
commands = [input() for _ in range(n)]

mark = [False] * n
values = {}


def get_value(x):
    return values.setdefault(x, 0) if x.isalpha() else int(x)


res, i = [], 0
while i < n and not mark[i]:
    mark[i] = True
    cmd, s = commands[i].split(maxsplit=1)

    if cmd == 'assign':
        a, _, b, _, c = s.split()
        values[a] = (get_value(b) + get_value(c)) % int(1e9 + 7)
    elif cmd == 'cout':
        res.append(get_value(s))

    if cmd == 'goto':
        i = get_value(s) - 1
    else:
        i += 1

print(-1 if i < n else '\n'.join(map(str, res)))
