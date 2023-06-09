from itertools import product

n, m = [int(x) for x in input().split()]

A = [input() for _ in range(n)]
B = [input() for _ in range(m)]

ans = False
for i, j in product(range(n), repeat=2):
    if i+m-1 >= n or j+m-1 >= n:
        continue

    val = True
    for k, l in product(range(m), repeat=2):
        val &= (B[k][l] == A[i+k][j+l])
    
    ans |= val

print("Yes") if ans else print("No")