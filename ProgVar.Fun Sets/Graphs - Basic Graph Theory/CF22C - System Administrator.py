n, m, v = [int(x) for x in input().split()]
if m < n-1:
    print(-1)
    exit(0)

edge_list = []
for i in range(1, n):
    edge_list.append((i, i+1))

count = len(edge_list)
for i in range(n-1):
    for j in range(i+2, n-1):
        if count < m:
            edge_list.append((i+1,j+1))
            count += 1
        else:
            break
    if count == m:
        break

if len(edge_list) < m:
    print(-1)
    exit(0)

for a, b in edge_list:
    if a == n-1:
        a = v
    elif a == v:
        a = n-1
    
    if b == n-1:
        b = v
    elif b == v:
        b = n-1

    print(a, b)