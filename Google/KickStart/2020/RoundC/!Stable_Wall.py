t = int(input())
for tc in range(t):
    r, c = map(int, input().split())
    wall = [input() for _ in range(r)][::-1]

    adj = {}
    for i, row in enumerate(wall):
        for j, v in enumerate(row):
            adj.setdefault(v, set())
            if i > 0:
                u = wall[i - 1][j]
                adj.setdefault(u, set())
                if u != v:
                    adj[u].add(v)

    deg = {}
    for u, vs in adj.items():
        deg.setdefault(u, 0)
        for v in vs:
            deg.setdefault(v, 0)
            deg[v] += 1

    q, res = [u for u, d in deg.items() if d == 0], ''
    while q:
        u = q.pop(0)
        res += u
        for v in adj[u]:
            if deg[v] == 0:
                continue
            deg[v] -= 1
            if deg[v] == 0:
                q.append(v)

    if len(res) != len(adj):
        res = "-1"

    print("Case #%s: %s" % (tc + 1, res))
