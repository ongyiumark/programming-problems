h, w = [int(x) for x in input().split()]
grid = [input() for _ in range(h)]
counts = [[0]*w for _ in range(h)]

for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            for di in range(-1,2):
                for dj in range(-1,2):
                    x = i+di
                    y = j+dj
                    if x < 0 or x >= h or y < 0 or y >= w:
                        continue
                    counts[x][y] += 1

for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            print("#", end="")
        else:
            print(counts[i][j], end="")
    print()