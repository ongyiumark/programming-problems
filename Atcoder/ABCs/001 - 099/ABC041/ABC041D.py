n, m = list(map(int, input().split()))
edges = []
for _ in range(m):
    x, y = list(map(int, input().split()))
    x -= 1
    y -= 1
    edges.append((x,y))

import sys
sys.setrecursionlimit(2**n)

memo = [None for _ in range(2**n)]
memo[0] = 1
def solve(mask):
    if memo[mask] is not None:
        return memo[mask]

    ans = 0 
    Sx = [False for _ in range(n)]
    for i in range(n):
        if (1<<i)&mask:
            Sx[i] = True

    for x, y in edges:
        if bool((1<<x)&mask) and bool((1<<y)&mask):
            Sx[y] = False
    
    for i in range(n):
        if Sx[i]:
            ans += solve(mask^(1<<i))
    
    memo[mask] = ans
    return ans

print(solve(2**n-1))