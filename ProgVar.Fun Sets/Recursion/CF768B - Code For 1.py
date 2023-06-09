from functools import lru_cache

n, l, r = [int(x) for x in input().split()]

@lru_cache(maxsize=None)
def count(n):
    if n <= 1:
        return 1
    return 2*count(n//2)+1

@lru_cache(maxsize=None)
def ones(n):
    if n <= 1:
        return n
    
    return 2*ones(n//2)+n%2

def solve(n, x):
    if n <= 1:
        return n

    if x <= count(n//2):
        return solve(n//2, x)
    elif x == count(n//2)+1:
        return ones(n//2)+n%2
    else:
        return ones(n//2)+n%2+solve(n//2, x-(count(n//2)+1))

if l == 1:
    print(solve(n,r))
else:
    print(solve(n,r)-solve(n,l-1))