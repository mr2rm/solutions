n = int(input())

snapshot, local, server = [], [], []
for _ in range(n):
    _, s = input().split(maxsplit=1)
    st = s.split(maxsplit=1)
    cmd = st[0]

    if cmd == 'add':
        local.append(st[1])
    elif cmd == 'clear':
        local.clear()
    elif cmd == 'del':
        if local:
            local.pop()
    elif cmd == 'commit':
        server = local[:]
        snapshot.append(local[:])
    elif cmd == 'checkout':
        local = snapshot[-2][:]
        server = snapshot[-2][:]
    elif cmd == 'pull':
        print(len(server))
        res = '\n'.join(server)
        if res:
            print(res)
