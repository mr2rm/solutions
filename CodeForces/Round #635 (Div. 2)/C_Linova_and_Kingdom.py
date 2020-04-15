n, k = map(int, input().split())

adj = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

# for i, x in enumerate(adj):
#     print(i, x)

dist = [-1] * (n + 1)
q, dist[1] = [1], 0
while q:
    u = q.pop(0)
    for v in adj[u]:
        if dist[v] == -1:
            dist[v] = dist[u] + 1
            q.append(v)

dist.sort()
res = sum(dist[-k:])
print(res)
