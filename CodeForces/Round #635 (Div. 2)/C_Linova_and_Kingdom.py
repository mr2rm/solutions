n, k = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

depth = [0] * (n + 1)
size = [1] * (n + 1)
score = [0] * (n + 1)
par = [0] * (n + 1)

q = [1]
depth[1], par[1] = 1, 0
while q:
    u = q.pop(0)
    for v in adj[u]:
        if v != par[u]:
            depth[v], par[v] = depth[u] + 1, u
            q.append(v)

for u in sorted(range(1, n + 1), key=lambda u: depth[u], reverse=True):
    for v in adj[u]:
        if v != par[u]:
            size[u] += size[v]
    score[u] = size[u] - depth[u]

score = sorted(score[1:])
res = sum(score[k:])
print(res)
