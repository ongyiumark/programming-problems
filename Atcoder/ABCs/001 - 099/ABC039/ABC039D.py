h, w = list(map(int, input().split()))
grid = []
for _ in range(h):
    grid.append(list(input()))

directions = [(-1,-1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1,-1), (1,0), (1,1)]
def expand(image):
    result = [[image[i][j] for j in range(w)] for i in range(h)]
    for i in range(h):
        for j in range(w):
            if image[i][j] != '.':
                continue
            for di, dj in directions:
                x = i+di
                y = j+dj
                if x < 0 or x >= h or y < 0 or y >= w:
                    continue
                result[x][y] = '.'
    return result

def shrink(image):
    result = [[image[i][j] for j in range(w)] for i in range(h)]
    for i in range(h):
        for j in range(w):
            if image[i][j] != '#':
                continue
            for di, dj in directions:
                x = i+di
                y = j+dj
                if x < 0 or x >= h or y < 0 or y >= w:
                    continue
                result[x][y] = '#'
    return result

def pprint(image):
    print('\n'.join([''.join(s) for s in image]))

expanded = expand(grid)
if shrink(expanded) == grid:
    print("possible")
    pprint(expanded)
else:
    print("impossible")
