from functools import lru_cache

n, x = [int(x) for x in input().split()]

@lru_cache(maxsize=None)
def burger_size(n):
    if n == 0:
        return 1
    return 3+2*burger_size(n-1)

@lru_cache(maxsize=None)
def patty_count(n):
    if n == 0:
        return 1
    return 1+2*patty_count(n-1)

def solve(n, x):
    if n == 0:
        return 1
    
    if x == 1:
        return 0
    elif x <= 1+burger_size(n-1):
        return solve(n-1, x-1)
    elif x == 2+burger_size(n-1):
        return 1+patty_count(n-1)
    else:
        return 1+patty_count(n-1)+solve(n-1, x-(2+burger_size(n-1)))

print(solve(n, x))