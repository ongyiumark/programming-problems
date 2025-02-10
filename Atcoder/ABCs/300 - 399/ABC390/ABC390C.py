H, W = list(map(int, input().split()))
grid = list()
for _ in range(H):
    grid.append(input())

top, bottom, left, right = H, 1, W, 1
for i in range(1, H+1):
    for j in range(1, W+1):
        ch = grid[i-1][j-1]
        if ch == "#":
            top = min(top, i)
            bottom = max(bottom, i)
            left = min(left, j)
            right = max(right, j)

possible = True
for i in range(top, bottom+1):
    for j in range(left, right+1):
        ch = grid[i-1][j-1]
        if ch == ".":
            possible = False
print("Yes" if possible else "No")

