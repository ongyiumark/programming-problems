n, m = [int(x) for x in input().split()]
adj_mat = [[False]*n for _ in range(n)]
deg = [0]*n
edge_list = []

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    adj_mat[a][b] = adj_mat[b][a] = True
    edge_list.append((a,b))
    deg[a] += 1
    deg[b] += 1

best = float('inf')
for u, v in edge_list:
    for i in range(n):
        if adj_mat[i][u] and adj_mat[i][v] and i != u and i != v:
            best = min(best, deg[u]+deg[v]+deg[i]-6)
if best < float('inf'):
    print(best)
else:
    print(-1)

