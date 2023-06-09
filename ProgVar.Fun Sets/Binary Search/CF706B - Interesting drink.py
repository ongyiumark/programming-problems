n = int(input())
X = sorted([int(x) for x in input().split()])
q = int(input())
M = [int(input()) for _ in range(q)]


for coins in M:
    lo = 0
    hi = n-1
    ans = 0
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if X[mid] <= coins:
            ans = mid+1
            lo = mid+1
        else:
            hi = mid-1
    
    print(ans)