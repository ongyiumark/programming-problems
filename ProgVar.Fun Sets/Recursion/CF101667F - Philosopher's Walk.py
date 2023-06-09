n, m = [int(x) for x in input().split()]

def length(n):
    return n*n

def solve(n, m):
    if n == 1:
        return 1, 1

    if m <= length(n//2):
        x, y = solve(n//2, m)
        x, y = y, n//2+1-x # rotate clockwise
        x, y = x, n//2+1-y # flip horizontally
        return x, y

    if m <= 2*length(n//2):
        x, y = solve(n//2, m-length(n//2))
        x, y = x, y+n//2 # shift up
        return x, y
        
    if m <= 3*length(n//2):
        x, y = solve(n//2, m-2*length(n//2))
        x, y = x+n//2, y+n//2 # shift up and right
        return x, y

    x, y = solve(n//2, m-3*length(n//2))
    x, y = n//2+1-y, x # rotate counterclockwise
    x, y = x, n//2+1-y # flip horizontally
    x, y = x+n//2, y # shift right
    return x, y

print(*solve(n, m))