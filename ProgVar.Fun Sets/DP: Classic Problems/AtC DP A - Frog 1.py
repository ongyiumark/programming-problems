from functools import lru_cache
import sys
sys.setrecursionlimit(10**6)

n = int(input())
h = [int(x) for x in input().split()]

@lru_cache(maxsize=None)
def solve(i):
    if i >= n-1:
        return 0
    
    if i+2 < n:
        return min(abs(h[i+2]-h[i])+solve(i+2), abs(h[i+1]-h[i])+solve(i+1))
    elif i+1 < n:
        return abs(h[i+1]-h[i])+solve(i+1)

print(solve(0))