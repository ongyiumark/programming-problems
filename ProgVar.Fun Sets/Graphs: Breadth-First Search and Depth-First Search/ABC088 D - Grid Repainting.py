from collections import deque

h, w = [int(x) for x in input().split()]
grid = [input() for _ in range(h)]

di = [0, 0, -1, 1]
dj = [-1, 1, 0, 0]

q = deque([(0,0)])
vis = [[False]*w for _ in range(h)]
dist = [[float('inf')]*w for _ in range(h)]
vis[0][0] = True
dist[0][0] = 1

while len(q) > 0:
    i, j = q.popleft()

    for k in range(4):
        x = i+di[k]
        y = j+dj[k]
        if x < 0 or x >= h or y < 0 or y >= w:
            continue
        if vis[x][y] or grid[x][y] == '#':
            continue
        vis[x][y] = True
        dist[x][y] = dist[i][j]+1
        q.append((x,y))

count_black = 0
for i in range(h):
    for j in range(w):
        count_black += (grid[i][j] == '#')

if not vis[h-1][w-1] or grid[i][j] == '#':
    print(-1)
else:
    print(h*w - count_black - dist[h-1][w-1])