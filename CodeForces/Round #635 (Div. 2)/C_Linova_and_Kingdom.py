n, k = map(int, input().split())
depth = [0] * (n + 1)
size = [0] * (n + 1)
score = [0] * (n + 1)

adj = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)


def dfs(p, q):
    depth[p], size[p] = depth[q] + 1, 1
    for r in adj[p]:
        if r != q:
            size[p] += dfs(r, p)

    score[p] = size[p] - depth[p]
    return size[p]


dfs(1, 0)
score = sorted(score[1:])
res = sum(score[k:])
print(res)
