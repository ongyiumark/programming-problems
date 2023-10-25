from collections import deque

n, m = [int(x) for x in input().split()]
adj_list = [[] for _ in range(3*n)]

def connect(u, v):
    adj_list[u].append(v)

for _ in range(m):
    u, v = [int(x)-1 for x in input().split()]

    connect(u, n+v)
    connect(n+u, 2*n+v)
    connect(2*n+u, v)

S, T = [int(x)-1 for x in input().split()]

q = deque([S])
dist = [float('inf')]*(3*n)
dist[S] = 0

while len(q) > 0:
    u = q.popleft()

    for v in adj_list[u]:
        if dist[v] < float('inf'): continue

        dist[v] = dist[u]+1
        q.append(v)

if dist[T] < float('inf'):
    print(dist[T]//3)
else:
    print(-1)

