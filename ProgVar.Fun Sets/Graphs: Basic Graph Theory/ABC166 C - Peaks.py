n, m = [int(x) for x in input().split()]
H = [int(x) for x in input().split()]

adj_list = [[] for _ in range(n)]
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    adj_list[a-1].append(b-1)
    adj_list[b-1].append(a-1)

count = 0
for u in range(n):
    val = True
    for v in adj_list[u]:
        val &= (H[u] > H[v])
    
    count += val
print(count)