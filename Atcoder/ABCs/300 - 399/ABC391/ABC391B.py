n, m = [int(x) for x in input().split()]
S, T = list(), list()
for _ in range(n):
    S.append(input())
for _ in range(m):
    T.append(input())

from itertools import product
# i+m-1 < n
# i < n-m+1
for i, j in product(range(n-m+1), repeat=2):
    found = True
    for _i, _j in product(range(m), repeat=2):
        x = i + _i
        y = j + _j

        found &= (S[x][y] == T[_i][_j])
    
    if found:
        print(i+1, j+1)
        break