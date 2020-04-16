from pprint import pprint
n, k = map(int, input().split())

adj = [[] for _ in range(n + 1)]
deg = [0] * (n + 1)
for _ in range(n - 1):
    u, v = map(int, input().split())
    adj[u].append(v)
    deg[u] += 1
    adj[v].append(u)
    deg[v] += 1

l = [(-deg[u], u) for u in range(1, n + 1)]
pprint(sorted(l))
is_tourist = [0] * (n + 1)
for _, u in sorted(l)[:-k]:
    is_tourist[u] = 1

tourist_count = [-1] * (n + 1)
q, tourist_count[1] = [1], 0
while q:
    u = q.pop(0)
    tourist_count[u] += is_tourist[u]

    for v in adj[u]:
        if tourist_count[v] != -1:
            continue

        tourist_count[v] = tourist_count[u]
        q.append(v)

res = sum(tourist_count[u] for u in range(1, n + 1) if is_tourist[u] == 0)
print(res)
