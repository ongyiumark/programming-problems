n, m = [int(x) for x in input().split()]
edge_list = []
for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    edge_list.append((a,b))


def dfs(u, vis, adj_list):
    vis[u] = True

    for v in adj_list[u]:
        if vis[v]:
            continue
        dfs(v, vis, adj_list)


def connected(edges, n):
    adj_list = [[] for _ in range(n)]
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)
    
    vis = [False]*n
    dfs(0, vis, adj_list)

    return sum(vis) == n

count = 0
for i in range(m):
    edges = edge_list[:i]+edge_list[i+1:]
    if not connected(edges, n):
        count += 1
    
print(count)
