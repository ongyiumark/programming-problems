from itertools import product

n, m = [int(x) for x in input().split()]
grid = [input() for _ in range(n)]
command = input()
og_grid = list(grid)

# 1 2 3             3 6 9
# 4 5 6     into    2 5 8
# 7 8 9             1 4 7
def rotate90(grid):
    return list(zip(*grid))[::-1]

def emptify(row, col):
    if og_grid[row][col].isdigit():
        return '0'
    return '.'

def gravity(grid):
    new_grid = []

    # process by column
    for col_idx, col in enumerate(zip(*grid)):
        col_n = len(col)
        col = list(col)+['#']
        for i in range(col_n, -1, -1):
            if not col[i].isalpha():
                continue

            for j in range(i+1, col_n+1):
                if col[j] == '#' or col[j].isalpha():
                    col[j-1] = col[i]
                    if j-1 != i:
                        col[i] = emptify(i, col_idx)
                    break
                elif col[j].isdigit():
                    if int(col[j]) == 0:
                        continue
                    col[j] = str(int(col[j])-1)
                    col[i] = emptify(i, col_idx)
                    break

        new_grid.append(col[:-1])
    return list(zip(*new_grid))      

def myprint(grid):
    for i in range(n):
        for j in range(m):
            print(grid[i][j], end="")
        print()

for ch in command:
    # rotate
    for _ in range("SWNE".index(ch)):
        grid = rotate90(grid)
        og_grid = rotate90(og_grid)

    # fall
    grid = gravity(grid)

    # rotate back
    for _ in range("SENW".index(ch)):
        grid = rotate90(grid)
        og_grid = rotate90(og_grid)

myprint(grid)
