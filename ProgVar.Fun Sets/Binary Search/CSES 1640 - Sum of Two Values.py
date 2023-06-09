import sys
input = sys.stdin.readline

n, x = [int(y) for y in input().split()]
A = [int(y) for y in input().split()]
A = list(enumerate(A))
A.sort(key = lambda x : x[-1])

for i in range(1,n):
    lo = 0
    hi = i-1
    ans = None

    to_find = x-A[i][-1]

    while lo <= hi:
        mid = hi - (hi-lo)//2
        if A[mid][-1] < to_find:
            lo = mid+1
        elif A[mid][-1] > to_find:
            hi = mid-1
        else:
            ans = mid
            print(A[i][0]+1, A[ans][0]+1)
            exit(0)

print("IMPOSSIBLE")