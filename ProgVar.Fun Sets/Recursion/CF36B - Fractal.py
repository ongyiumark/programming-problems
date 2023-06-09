from itertools import product

with open('input.txt', 'r') as f:
    lines = f.readlines()

    n, k = [int(x) for x in lines[0].split()]
    template = [x.strip() for x in lines[1:]]


def solve(n, k):
    if k == 1:
        return [list(x) for x in template]

    res = [['.']*(n**k) for _ in range(n**k)]
    for i, j in product(range(n), repeat=2):
        if template[i][j] == '*':
            for ii, jj in product(range(n**(k-1)), repeat=2):
                x = i*(n**(k-1))+ii
                y = j*(n**(k-1))+jj
                res[x][y] = '*'
        else:
            nxt = solve(n, k-1)
            for ii, jj in product(range(n**(k-1)), repeat=2):
                x = i*(n**(k-1))+ii
                y = j*(n**(k-1))+jj
                res[x][y] = nxt[ii][jj]
    
    return res

with open('output.txt', 'w') as f:       
    for lst in solve(n, k):
        f.write(''.join(lst)+'\n')