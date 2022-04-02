import sys
input = sys.stdin.readline

N, X = [int(x) for x in input().split()]
t = [int(x) for x in input().split()]

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

def lcm(a, b):
    return a//gcd(a,b)*b

def solve(T, i, L, sign):
    if L > T: return 0
    if i == len(t):
        return sign*(T//L)
    return solve(T, i+1, L, sign) + solve(T, i+1, lcm(L,t[i]), -sign)

lo = 0
hi = 10**18
ans = -1
while lo <= hi:
    mid = hi - (hi-lo)//2
    if solve(mid, 0, 1, -1)+mid >= X:
        ans = mid
        hi = mid-1
    else: lo = mid+1

print(ans)
