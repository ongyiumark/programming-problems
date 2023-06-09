n = int(input())
A = [int(x) for x in input().split()]

from functools import lru_cache

@lru_cache(maxsize=None)
def solve(i):
    if i == 0:
        return A[i]
    
    return max(A[i], solve(i-1)+A[i])

print(max([solve(i) for i in range(n)]))