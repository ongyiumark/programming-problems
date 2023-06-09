from collections import deque

n = int(input())
p = [int(x) for x in input().split()]
mat = [input() for _ in range(n)]
adj_list = [[] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if mat[i][j] == '1':
            adj_list[i].append(j)

def bfs(s, vis):
    q = deque([s])
    vis[s] = True

    ans, idx = p[s], s
    while len(q) > 0:
        u = q.popleft()
        if p[u] < ans and u > s:
            ans = p[u]
            idx = u

        for v in adj_list[u]:
            if vis[v]: continue

            vis[v] = True
            q.append(v)
    
    return idx

for i in range(n):
    vis = [False]*n

    idx = bfs(i, vis)
    p[i], p[idx] = p[idx], p[i]

print(*p)