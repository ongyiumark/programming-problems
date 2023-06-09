from collections import deque

n, m, k = [int(x) for x in input().split()]
grid = [list(input()) for _ in range(n)]

di = [0,0,-1,1]
dj = [1,-1,0,0]

s = 0
for i in range(n):
    for j in range(m):
        s += (grid[i][j] == '.')

        if grid[i][j] == '.':
            si, sj = i, j

vis = [[False]*m for _ in range(n)]
q = deque([(si, sj)])
vis[si][sj] = True

count = 0
while len(q) > 0:
    i, j = q.popleft()
    grid[i][j] = '0'
    count += 1
    if count == s-k:
        break

    for kk in range(4):
        x = i + di[kk]
        y = j + dj[kk]

        if x < 0 or x >= n or y < 0 or y >= m:
            continue
        if grid[x][y] == '#' or vis[x][y]:
            continue
        
        vis[x][y] = True
        q.append((x,y))

for row in grid:
    for j in range(m):
        if row[j] == '.':
            row[j] = 'X'
        if row[j] == '0':
            row[j] = '.'
    
    print(''.join(row))
        
