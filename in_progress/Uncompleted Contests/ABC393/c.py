n, m = list(map(int, input().split()))
count = 0

s = set()
for i in range(m):
    u, v = list(map(int, input().split()))
    u, v = min(u,v), max(u,v)
    if u == v or (u, v) in s:
        count += 1
    s.add((u,v))
    
print(count)