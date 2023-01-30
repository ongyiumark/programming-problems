import sys
input = sys.stdin.readline

n, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

def opt(x):
    cnt = 0
    for a in A:
        cnt += ((a+x-1)//x)-1
    return cnt <= k

ans = 0
lo = 1
hi = 10**9
while lo <= hi:
    mid = (lo+hi)//2
    if opt(mid):
        ans = mid
        hi = mid-1
    else:
        lo = mid+1

print(ans)