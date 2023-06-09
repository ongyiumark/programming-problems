import sys
input = sys.stdin.readline

n, x = [int(y) for y in input().split()]
A = [int(y) for y in input().split()]
A = list(enumerate(A))
A.sort(key = lambda x : x[-1])

for i in range(1,n):
    for j in range(1, i):
        lo = 0
        hi = j-1
        ans = None

        to_find = x-A[i][-1]-A[j][-1]

        while lo <= hi:
            mid = hi - (hi-lo)//2
            if A[mid][-1] < to_find:
                lo = mid+1
            elif A[mid][-1] > to_find:
                hi = mid-1
            else:
                ans = mid
                print(A[i][0]+1, A[j][0]+1, A[ans][0]+1)
                exit(0)

print("IMPOSSIBLE")