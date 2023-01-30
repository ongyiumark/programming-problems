from functools import lru_cache
import sys

sys.setrecursionlimit(10**9)
h, n = [int(x) for x in input().split()]

a = [0 for x in range(n)]
b = [0 for x in range(n)]
for i in range(n):
    u, v = [int(x) for x in input().split()]
    a[i] = u
    b[i] = v

@lru_cache(maxsize=None)
def solve(hh):
    if hh <= 0: return 0
    ans = 10**9
    for u,v in zip(a,b):
        ans = min(ans, solve(hh-u)+v)
    return ans

print(solve(h))