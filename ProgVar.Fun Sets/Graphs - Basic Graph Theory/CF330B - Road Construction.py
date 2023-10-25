n, m = [int(x) for x in input().split()]
found = [False]*n

for _ in range(m):
    a, b = [int(x)-1 for x in input().split()]
    found[a] = found[b] = True

idx = -1
for i in range(n):
    if not found[i]:
        idx = i

edges = []
for i in range(n):
    if i == idx: continue
    edges.append((i+1,idx+1))

print(len(edges))
for edge in edges:
    print(*edge)