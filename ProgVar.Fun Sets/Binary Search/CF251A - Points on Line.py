n, d = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

total = 0
for i in range(n):
    lo = i+2
    hi = n-1
    ans = None

    while lo <= hi:
        mid = hi - (hi -lo)//2
        if A[mid] - A[i] <= d:
            lo = mid+1
            ans = mid
        else:
            hi = mid-1

    if ans != None:
        k = ans-i
        total += (k-1)*k//2
print(total)