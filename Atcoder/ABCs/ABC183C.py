# Brute force

import sys
sys.setrecursionlimit(10**9)


n, k = [int(x) for x in input().split()]
T = [[0 for j in range(n)] for i in range(n)]

for i in range(n):
    T[i] = [int(x) for x in input().split()]

vis = [False for x in range(n)]
a = []
ans = 0

def solve():
    global ans
    if len(a) == n-1:
        total = T[0][a[0]]
        for i in range(1, n-1):
            total += T[a[i-1]][a[i]]
        total += T[a[n-2]][0]
        ans += (total == k)
        return

    for i in range(1, n):
        if vis[i]: continue
        vis[i] = True
        a.append(i)
        solve()
        a.pop()
        vis[i] = False

solve()
print(ans)