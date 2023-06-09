from functools import lru_cache
import sys
sys.setrecursionlimit(10**6)

n, k = [int(x) for x in input().split()]
h = [int(x) for x in input().split()]

@lru_cache(maxsize=None)
def solve(i):
    if i >= n-1:
        return 0
    
    ans = float('inf')
    for j in range(1, k+1):
        if i + j >= n:
            break
        ans = min(ans, abs(h[i]-h[i+j])+solve(i+j))

    return ans

print(solve(0))