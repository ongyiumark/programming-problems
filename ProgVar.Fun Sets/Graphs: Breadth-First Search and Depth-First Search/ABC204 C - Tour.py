import sys
sys.setrecursionlimit(10**4)

n, m = [int(x) for x in input().split()]
adj_list = [[] for _ in range(n)]

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    adj_list[a].append(b)

def dfs(u, vis):
    vis[u] = True
    
    for v in adj_list[u]:
        if vis[v]:
            continue
        dfs(v, vis)

count = 0
for i in range(n):
    vis = [False for _ in range(n)]
    dfs(i, vis)
    count += sum(vis)

print(count)