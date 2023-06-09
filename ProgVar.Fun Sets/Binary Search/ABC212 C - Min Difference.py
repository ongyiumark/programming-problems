n, m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

A.sort()
B.sort()

result = float('inf')
for x in A:
    lo = 0
    hi = m-1
    ans = None

    while lo <= hi:
        mid = hi - (hi-lo)//2
        if B[mid] <= x:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    
    if ans == None:
        result = min(result, abs(x-B[0]))
    elif ans == m-1:
        result = min(result, abs(x-B[ans]))
    else:
        result = min(result, min(abs(x-B[ans]), abs(x-B[ans+1])))
    
print(result)