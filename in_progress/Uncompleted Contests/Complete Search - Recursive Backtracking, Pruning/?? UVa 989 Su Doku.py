import sys

lines = sys.stdin.readlines()
sz = len(lines)
idx = 0
found = False

def backtrack(i, j, col, row, block, grid, n):
    global found
    if found:
        return

    if i == n*n:
        found = True
        for res in grid:
            print(*res)
        return

    if j == n*n:
        backtrack(i+1, 0, col, row, block, grid, n)
        return

    if grid[i][j] > 0:
        backtrack(i, j+1, col, row, block, grid, n)
    else:
        for d in range(1, n*n+1):
            grid[i][j] = d
            if col[j][grid[i][j]] or row[i][grid[i][j]] or block[i//n][j//n][grid[i][j]]:
                grid[i][j] = 0
                continue

            col[j][grid[i][j]] = True
            row[i][grid[i][j]] = True
            block[i//n][j//n][grid[i][j]] = True

            backtrack(i, j+1, col, row, block, grid, n)

            col[j][grid[i][j]] = False
            row[i][grid[i][j]] = False
            block[i//n][j//n][grid[i][j]] = False

            grid[i][j] = 0   

def solve(grid, n):
    global found 
    found = False
    col = [[False]*(n*n+1) for _ in range(n*n)]
    row = [[False]*(n*n+1) for _ in range(n*n)]
    block = [[[False]*(n*n+1) for j in range(n)] for i in range(n)]
    found = False

    for i in range(n*n):
        for j in range(n*n):
            if grid[i][j] > 0:
                col[j][grid[i][j]] = True
                row[i][grid[i][j]] = True
                block[i//n][j//n][grid[i][j]] = True

    backtrack(0, 0, col, row, block, grid, n)

    if not found:
        print("NO SOLUTION")

while idx < sz:
    n = int(lines[idx])
    idx += 1

    grid = [[0]*(n*n) for _ in range(n*n)]

    for i in range(n*n):
        grid[i] = [int(x) for x in lines[idx+i].split()]

    idx += n*n + 1
    solve(grid, n)
    if idx < sz:
        print()
