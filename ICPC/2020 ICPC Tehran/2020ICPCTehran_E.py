import sys
input = sys.stdin.readline

# read
n, m = [int(x) for x in input().split()]
grid = [input() for i in range(n)]

cnt = 0

from collections import deque
q = deque([])
d = [[float('inf')]*m for i in range(n)]
for i in range(n):
  for j in range(m):
    if grid[i][j] == "*":
      q.append((i, j))
      d[i][j] = 0
      cnt += 1
    elif grid[i][j] == "S":
      s = (i,j)
    elif grid[i][j] == "E":
      e = (i,j)

# compute distances
di = [1,-1,0,0,1,1,-1,-1]
dj = [0,0,1,-1,-1,1,1,-1]
while len(q) > 0:
  ci, cj = q.popleft()

  for k in range(8):
    x = ci+di[k]
    y = cj+dj[k]
    if x < 0 or x >= n or y < 0 or y >= m:
      continue
    if d[x][y] < float('inf'):
      continue
    d[x][y] = d[ci][cj]+1
    q.append((x,y))


vis = [[False]*m for i in range(n)]
nd = [[float('inf')]*m for i in range(n)]
si, sj = s
vis[si][sj] = True
found = False

from heapq import heappush, heappop
pq = []
heappush(pq, (-d[si][sj], si, sj))
while (len(pq) > 0):
  w, ci, cj = heappop(pq)

  if (ci, cj) == e:
    found = True

  for k in range(4):
    x = ci+di[k]
    y = cj+dj[k]
    if x < 0 or x >= n or y < 0 or y >= m:
      continue
    if vis[x][y] or grid[x][y] in "#*":
      continue
    
    vis[x][y] = True
    nd[x][y] = min(nd[ci][cj], d[x][y])
    heappush(pq, (-d[x][y], x, y))

ei, ej = e
if not found: print(-1)
elif cnt == 0: print("safe")
else: print(nd[ei][ej])



