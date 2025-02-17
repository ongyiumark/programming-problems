n, m, p = list(map(int, input().split()))
edges = [None]*m
for i in range(m):
    a, b, c = list(map(int, input().split()))
    a -= 1
    b -= 1
    w = p-c
    edges[i] = (a,b,w)

d = [float("inf")]*n
d[0] = 0
for i in range(n-1):
    for u, v, w in edges:
        d[v] = min(d[v], d[u]+w)

for i in range(n-1):
    for u, v, w in edges:
        if d[v] > d[u] + w:
            d[v] = -float("inf")

if d[n-1] == -float("inf"):
    print(-1)
else:
    print(max(-d[n-1],0))