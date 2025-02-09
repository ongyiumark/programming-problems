x = input()
m = int(input())

def convert(x, b):
    p = 1
    ans = 0
    for c in x[::-1]:
        ans += int(c)*p
        p *= b 
    return ans

if len(x) == 1:
    print(1 if int(x) <= m else 0)
else:
    d = max([int(c) for c in x])+1
    lo = d
    hi = 10**18
    ans = d-1
    while lo <= hi:
        mid = hi - (hi-lo)//2
        if convert(x, mid) <= m:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    print(ans-d+1)