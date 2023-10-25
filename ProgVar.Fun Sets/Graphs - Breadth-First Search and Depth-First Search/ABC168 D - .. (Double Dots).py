from collections import deque

n, m = [int(x) for x in input().split()]
adj_list = [[] for _ in range(n)]

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    adj_list[a].append(b)
    adj_list[b].append(a)

par = [-1]*n
vis = [False]*n
q = deque([0])
vis[0] = True
while len(q) > 0:
    u = q.popleft()

    for v in adj_list[u]:
        if vis[v]:
            continue
        q.append(v)
        par[v] = u+1
        vis[v] = True

if sum(vis) == n:
    print("Yes")
    print(*par[1:], sep='\n')
else:
    print("No")