k = int(input())

vis = [False for _ in range(k)]
vis[0] = True

curr = 7%k
cnt = 0
while not vis[curr]:
    vis[curr] = True
    curr = (curr*10+7)%k
    cnt += 1

if curr == 0:
    print(cnt+1)
else:
    print(-1)