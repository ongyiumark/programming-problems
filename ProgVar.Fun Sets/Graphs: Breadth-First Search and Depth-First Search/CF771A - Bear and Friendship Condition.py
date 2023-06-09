import sys
from collections import deque
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
adj_list = [[] for _ in range(n)]

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    adj_list[a].append(b)
    adj_list[b].append(a)

components = [0]*n
vis = [False]*n
def bfs(s, i):
    q = deque([s])
    vis[s] = True

    while len(q) > 0:
        u = q.popleft()    
        components[i] += 1

        for v in adj_list[u]:
            if vis[v]:
                continue
            vis[v] = True
            q.append(v)
        

idx = 0
for i in range(n):
    if vis[i]:
        continue
    bfs(i, idx)
    idx += 1

need = 0
for sz in components:
    need += sz*(sz-1)//2
    if need > m:
        print("NO")
        exit(0)

print("YES") if need == m else print("NO")
    