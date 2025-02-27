n = int(input())

adj_list = dict()
def add_edge(u, v):
    if u not in adj_list:
        adj_list[u] = list()
    adj_list[u].append(v)

for i in range(n):
    A = list(map(int, input().split()))
    for j in range(1,n-1):
        add_edge((min(i+1, A[j-1]), max(i+1, A[j-1])), (min(i+1, A[j]), max(i+1, A[j])))


dist = dict()
vis = dict()    

st = list()
cycle = False
for i in range(1,n):
    for j in range(i+1, n+1):
        s = (i, j)
        if vis.get(s, 0) == 2:
            continue
        
        st.append(s)
        while len(st) > 0:
            u = st[-1]
            if vis.get(u, 0) == 0:
                vis[u] = 1
            else:
                vis[u] = 2
                st.pop()
            
            if vis[u] == 2:
                dist[u] = 1

            for v in adj_list.get(u, []):
                if vis[u] == 2:
                    dist[u] = max(dist[u], dist.get(v,0)+1)
                    continue

                if vis.get(v, 0) == 0:
                    st.append(v)
                elif vis.get(v, 0) == 1:
                    cycle = True
                

print(max([val for key, val in dist.items()]) if not cycle else -1)
