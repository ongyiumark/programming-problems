from collections import deque

h, w = [int(x) for x in input().split()]
grid = [input() for _ in range(h)]

di = [0,0,-1,1]
dj = [-1,1,0,0]
def solve(ci, cj):
    q = deque([(ci, cj)])
    dist = [[float('inf')]*w for _ in range(h)]
    dist[ci][cj] = 0

    best = 0
    while len(q) > 0:
        i, j = q.popleft()
        best = max(best, dist[i][j])

        for k in range(4):
            x = i + di[k]
            y = j + dj[k]

            if x < 0 or x >= h or y < 0 or y >= w:
                continue
            if dist[x][y] < float('inf') or grid[x][y] == '#':
                continue
            dist[x][y] = dist[i][j]+1
            q.append((x,y))
    return best

ans = -float('inf')
for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            continue
        ans = max(ans, solve(i, j))
print(ans)